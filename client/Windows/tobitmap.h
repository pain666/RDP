#pragma once
#include <windows.h>
#include <gdiplus.h>
#include <malloc.h>
#include <stdlib.h>
using namespace Gdiplus;

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}

void Example_SaveFile(HDC hdc)
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Create an Image object based on a PNG file.
	Image image(L"D:\\FreeRDP-master\\Debug\\Images\\1.png");

	//Image* image = new Image(L"D:\\FreeRDP-master\\Debug\\Images\\1.png");
	//printf("The width of the image is %u.\n", image->GetWidth());
	//printf("The height of the image is %u.\n", image->GetHeight());

	Graphics graphics(hdc);

	// Draw the image.
	graphics.DrawImage(&image, 10, 10);

	// Construct a Graphics object based on the image.
	Graphics imageGraphics(&image);

	// Alter the image.
	SolidBrush brush(Color(255, 0, 0, 255));
	imageGraphics.FillEllipse(&brush, 20, 30, 80, 50);

	// Draw the altered image.
	graphics.DrawImage(&image, 200, 10);

	// Save the altered image.
	CLSID pngClsid;
	GetEncoderClsid(L"image/png", &pngClsid);
	image.Save(L"D:\\FreeRDP-master\\Debug\\Images\\12.png", &pngClsid, NULL);
}

//
//void toBitmap()
//{
//	GdiplusStartupInput gdiplusStartupInput;
//	ULONG_PTR gdiplusToken;
//	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
//
//	HBITMAP hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), (LPCWSTR)"babe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
//
//	Bitmap *image = new Bitmap(hBitmap, NULL);
//	CLSID myClsId;
//	int retVal = GetEncoderClsid(L"image/bmp", &myClsId);
//	image->Save(L"output.bmp", &myClsId, NULL);
//	delete image;
//
//	GdiplusShutdown(gdiplusToken);
//}