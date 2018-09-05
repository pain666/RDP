#pragma once
#include <windows.h>
#include <gdiplus.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale>
#include <codecvt>
#include <string>
#include <iostream>
#include <Objbase.h>
#include <wingdi.h>
#include <vector>
#include "FrameBuffer.h"
#include <ctime>
#include <thread>
#include <fstream>
#include <shlwapi.h>

using namespace Gdiplus;

class GdiImageDumper {
public:
	static GdiImageDumper& instance()
	{
		static GdiImageDumper s;
		return s;
	}

	void saveFrame(HBITMAP bitmap, HDC hdc)
	{
		if (isLocked) {
			std::cerr << "Attemp to save image in locked state\n";
			return;
		}

		if (!bInitialized) {
			std::cerr << "Dumper is not initialized\n";
			return;
		}

		BITMAP bm;
		GetObject(bitmap, sizeof(bm), (LPVOID)&bm);

		//TODO IMPORTANT:	Threads synchronization is needed to lock the write.
		//					Right now it is very easy to catch access violation crash on iterator accessing frames in dump()
		frameBuffer->add((LICE_pixel*)bm.bmBits);
	}


	void dump()
	{
		if (!bInitialized) {
			std::cerr << "Dumper is not initialized\n";
			return;
		}

		isLocked = true;

		void *outputGif = NULL;
		int lastBitmapRect[4] = {0,0,1800,900};
		LICE_pixel blackMask = LICE_RGBA(0xff, 0xff, 0xff, 0);
		LICE_IBitmap *lastBitmap;
		for (auto it = frameBuffer->begin(); it != frameBuffer->end(); ++it) {
			if (!outputGif)
			{
				outputGif = LICE_WriteGIFBegin((path + "\\RDPdump.gif").c_str(), it->bitmap.get(), 0, 50, false);
				if (!outputGif) std::cerr << "Error writing LICEgif to file\n";
			}
			else
			{
				//Check the difference from previous bitmap
				LICE_BitmapCmpEx(lastBitmap, it->bitmap.get(), blackMask, lastBitmapRect);

				//Modify to avoid storing same areas
				LICE_Blit(lastBitmap, it->bitmap.get(),
					lastBitmapRect[0],
					lastBitmapRect[1],
					lastBitmapRect[0],
					lastBitmapRect[1],
					lastBitmapRect[2],
					lastBitmapRect[3], 1.0f, LICE_BLIT_MODE_COPY);

				if (lastBitmap && lastBitmapRect[2] > 0 && lastBitmapRect[3] > 0)
				{
					LICE_SubBitmap bm(lastBitmap, lastBitmapRect[0], lastBitmapRect[1], lastBitmapRect[2], lastBitmapRect[3]);

					auto delay = std::chrono::duration_cast<std::chrono::milliseconds>(it->timestamp - (it-1)->timestamp).count();
					LICE_WriteGIFFrame(outputGif, &bm, lastBitmapRect[0], lastBitmapRect[1], true, delay);
				}

				lastBitmapRect[2] = lastBitmapRect[3] = 0;
			}

			lastBitmap = it->bitmap.get();
		}

		if (outputGif) {
			if (LICE_WriteGIFEnd(outputGif))
			{
				std::cout << "Gif dump SUCCESS";
			}
			else {
				std::cout << "Gif dump FAIL";
			}
		}

		isLocked = false;
	}

	/* GUIDs for different formats:
		bmp:	{557cf400-1a04-11d3-9a73-0000f81ef32e}
		jpeg:	{557cf401-1a04-11d3-9a73-0000f81ef32e}
		gif:	{557cf402-1a04-11d3-9a73-0000f81ef32e}
		tiff:	{557cf405-1a04-11d3-9a73-0000f81ef32e}
		png:	{557cf406-1a04-11d3-9a73-0000f81ef32e}
	*/
	void dumpToPng(HBITMAP bitmap)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		std::wstring wpath = converter.from_bytes(path);
		CLSID clsid;
		CLSIDFromString(L"{557cf400-1a04-11d3-9a73-0000f81ef32e}", &clsid);

		Bitmap image(bitmap, NULL);
		std::wstring imagePath = wpath + L"\\image" + std::to_wstring(saveIndex++) + L".bmp";
		image.Save(imagePath.data(), &clsid, NULL);
	}

	void dumpToBin(uint8_t* buf, size_t size, std::string ext = ".data") {
		std::string imagePath = path + "\\image" + std::to_string(saveIndex++) + ext;
		auto file = std::fstream(imagePath, std::ios::out | std::ios::binary);
		file.write((char*)buf, size);
		file.close();
	}

	void initialize(std::string str, unsigned int frameW, unsigned int frameH)
	{
		if (bInitialized) {
			return;
		}

		struct stat s;
		if (!(stat(str.data(), &s) == 0 && s.st_mode & S_IFDIR)) {
			std::cerr << "Image dump directory does not exist\n";
			return;
		}

		GdiplusStartupInput gdiplusStartupInput;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		path = str;

		frameBuffer.reset(new FrameBuffer(frameW, frameH));

		bInitialized = true;
	}

	bool isInitialized()
	{
		return bInitialized;
	}

/*
=======================================================================
	SET OF FUNCTIONS THAT DO NOT WORK PROPERLY SO FAR OR USELESS
=======================================================================
*/

	// FOR TESTING
	// Does not compress image for some reason
	BYTE* savePngToMem(HBITMAP bitmap, DWORD * size)
	{
		CLSID clsid;
		CLSIDFromString(L"{557cf400-1a04-11d3-9a73-0000f81ef32e}", &clsid);
		Bitmap image(bitmap, NULL);

		IStream *stream = NULL;
		HRESULT hr = CreateStreamOnHGlobal(0, TRUE, &stream);
		if (!SUCCEEDED(hr))
			return nullptr;
		image.Save(stream, &clsid, NULL);
		ULARGE_INTEGER liSize;
		IStream_Size(stream, &liSize);
		*size = liSize.LowPart;
		IStream_Reset(stream);
		BYTE * buf = new BYTE[*size];
		IStream_Read(stream, &buf[0], *size);
		stream->Release();
		return buf;
	}


	// FOR TESTING
	// Not used so far as LICE lib can not store gifs in 8bpp
	HBITMAP CopyTo8Bpp(HBITMAP hbm, HDC hdc)
	{
		int bpp = 8;
		int w = frameBuffer->getWidth(), h = frameBuffer->getHeight();

		// "BITMAPINFO" is an interop-struct which we define below.
		// In GDI terms, it's a BITMAPHEADERINFO followed by an array of two RGBQUADs
		BITMAPINFO* bmInfo = (BITMAPINFO*)new(char[sizeof(BITMAPINFO) + sizeof(BITMAPINFO::bmiColors) * 256]);
		auto z = sizeof(BITMAPINFO::bmiColors);
		auto && bmi = bmInfo->bmiHeader;
		bmi.biSize = 40;  // the size of the BITMAPHEADERINFO struct
		bmi.biWidth = w;
		bmi.biHeight = h;
		bmi.biPlanes = 1; // "planes" are confusing. We always use just 1. Read MSDN for more info.
		bmi.biBitCount = (short)bpp; // ie. 1bpp or 8bpp
		bmi.biCompression = BI_RGB; // ie. the pixels in our RGBQUAD table are stored as RGBs, not palette indexes
		bmi.biSizeImage = (size_t)(((w + 7) & 0xFFFFFFF8)*h / 8);
		bmi.biXPelsPerMeter = 1000000; // not really important
		bmi.biYPelsPerMeter = 1000000; // not really important
		// Now for the colour table.
		size_t ncols = (size_t)1 << bpp; // 2 colours for 1bpp; 256 colours for 8bpp
		auto cols = bmInfo->bmiColors;
		bmi.biClrUsed = 216;
		bmi.biClrImportant = 216;
		BYTE colv[6] = { 0,51,102,153,204,255 };
		for (int i = 0; i < 216; i++)
		{
			cols[i] = RGBQUAD{ colv[i % 6], colv[(i / 6) % 6], colv[i / 36], 0 };
		}

		int* out;
		auto hbm0 = CreateDIBSection(0, bmInfo, DIB_RGB_COLORS, (void**)(&out), nullptr, 0);
		auto hdc0 = CreateCompatibleDC(hdc);
		SelectObject(hdc0, hbm0);
		auto b = BitBlt(hdc0, 0, 0, w, h, hdc, 0, 0, SRCCOPY);

		DeleteDC(hdc0);

		return hbm0;
	}

	// FOR TESTING
	//Does not work properly so far
	HBITMAP CopyTo32Bpp(HBITMAP hbm, HDC hdc)
	{
		BITMAP  bmp;
		if (GetObject(hbm, sizeof(bmp), &bmp))
		{
			if (8 == bmp.bmBitsPixel)
			{
				int             cy = 0 < bmp.bmHeight ? bmp.bmHeight : -bmp.bmHeight;
				unsigned int    bpl8 = (bmp.bmWidth + 3)&~3;
				unsigned int    bpl32 = 4 * bmp.bmWidth;
				unsigned char*  lp8 = (unsigned char*)malloc(bpl8*cy);
				unsigned char*  lp32 = (unsigned char*)malloc(bpl32*cy);
				HDC             mdc = CreateCompatibleDC(0);
				BITMAPINFO*     pbmi = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + (256 * sizeof(RGBQUAD)));
				int             x, y;
				unsigned char*  lpdst = lp32;
				unsigned char*  lpsrc = lp8;

				pbmi->bmiHeader.biSize = sizeof(BITMAPINFO) + (256 * sizeof(RGBQUAD));
				GetDIBits(mdc, hbm, 0, cy, lp8, pbmi, DIB_RGB_COLORS);
				for (y = 0; y < cy; y++)
				{
					for (x = 0; x < bmp.bmWidth; x++)
					{
						lpdst[(x << 2) + 0] = pbmi->bmiColors[lpsrc[x]].rgbBlue;
						lpdst[(x << 2) + 1] = pbmi->bmiColors[lpsrc[x]].rgbGreen;
						lpdst[(x << 2) + 2] = pbmi->bmiColors[lpsrc[x]].rgbRed;
						lpdst[(x << 2) + 3] = 0x00;
					}
					lpdst += bpl32;
					lpsrc += bpl8;
				}

				pbmi->bmiHeader.biSize = sizeof(BITMAPINFO);
				pbmi->bmiHeader.biPlanes = 1;
				pbmi->bmiHeader.biBitCount = 32;
				pbmi->bmiHeader.biCompression = 0;
				pbmi->bmiHeader.biSizeImage = bpl32 * cy;
				pbmi->bmiHeader.biClrUsed = 0;
				pbmi->bmiHeader.biClrImportant = 0;

				HBITMAP hbmp32 = CreateDIBitmap(mdc, &pbmi->bmiHeader, CBM_INIT, lp32, pbmi, DIB_RGB_COLORS);

				DeleteDC(mdc);
				free(pbmi);
				free(lp8);
				free(lp32);
				return hbmp32;
			}
		}
		return 0;
	}

	// FOR TESTING
	// The resulting gif files are too big
	void dumpToGifOverGdi(HBITMAP bitmap, HDC hdc)
	{
		static int saveIndex = 0;
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		std::wstring wpath = converter.from_bytes(path);
		CLSID clsid;
		CLSIDFromString(L"{557cf402-1a04-11d3-9a73-0000f81ef32e}", &clsid);

		std::wstring imagePath = wpath + L"\\image" + std::to_wstring(saveIndex++) + L".gif";

		static int count = 0;
		static int frameCount = 150;

		static EncoderParameters* encoderParameters;
		ULONG parameterValue = EncoderValueMultiFrame;
		ULONG parameterValue2 = EncoderValueCompressionLZW;
		static Bitmap * firstGIf;
		if (count == 0) {

			encoderParameters = (EncoderParameters*)malloc(sizeof(EncoderParameters) * 3);
			encoderParameters->Count = 3;

			// the for loop is pointless and does nothing
			encoderParameters->Parameter[0].Guid = EncoderSaveFlag;
			encoderParameters->Parameter[0].Type = EncoderParameterValueTypeLong;
			encoderParameters->Parameter[0].NumberOfValues = 1;
			encoderParameters->Parameter[0].Value = &parameterValue;

			encoderParameters->Parameter[1].Guid = EncoderCompression;
			encoderParameters->Parameter[1].Type = EncoderParameterValueTypeLong;
			encoderParameters->Parameter[1].NumberOfValues = 1;
			encoderParameters->Parameter[1].Value = &parameterValue2;

			firstGIf = Bitmap::FromHBITMAP(CopyTo8Bpp(bitmap, hdc), 0);
			firstGIf->Save(imagePath.data(), &clsid, encoderParameters);
		}
		else if (count < frameCount) {
			Bitmap image(CopyTo8Bpp(bitmap, hdc), NULL);

			if (count == frameCount - 1)
			{
				parameterValue = EncoderValueLastFrame;
			}
			else
			{
				ULONG value[2];
				value[0] = EncoderValueFrameDimensionTime;
				value[1] = 10;

				encoderParameters->Parameter[0].Value = value;
				auto status = firstGIf->SaveAdd(&image, encoderParameters);
			}
		}
		else if (count == frameCount) {
			encoderParameters->Parameter[0].Value = &parameterValue;
			parameterValue = EncoderValueFlush;
			firstGIf->SaveAdd(encoderParameters);
		}

		++count;
	}

private:
	GdiImageDumper() {}

	~GdiImageDumper()
	{
		GdiplusShutdown(gdiplusToken);
	}

	ULONG_PTR gdiplusToken = 0;

	bool bInitialized = false;
	int saveIndex = 0;
	bool isLocked = false;

	std::string path;
	std::unique_ptr<FrameBuffer> frameBuffer;
};