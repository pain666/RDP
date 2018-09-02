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
#include "ImageProcessing/gif.h"
#include <ctime>
using namespace Gdiplus;

class GdiImageDumper {
public:
	static GdiImageDumper& instance()
	{
		static GdiImageDumper s;
		return s;
	}

	void saveFrame(HBITMAP bitmap)
	{
		if (isLocked) {
			std::cerr << "Attemp to save image in locked state\n";
			return;
		}

		if (bInitialized) {
			std::cerr << "Dumper is not initialized\n";
			return;
		}

		BITMAP bm;
		GetObject(bitmap, sizeof(bm), (LPVOID)&bm);
		frameBuffer.add((uint8_t*)bm.bmBits);
	}

	void dump()
	{
		if (bInitialized) {
			std::cerr << "Dumper is not initialized\n";
			return;
		}

		isLocked = true;
		GifBegin(&writer, (path + "\\F.gif").c_str(), frameBuffer.frameW, frameBuffer.frameH, 0);
		int count = 0;
		for (auto it = frameBuffer.begin(); it != frameBuffer.end(); ++it) {
			GifWriteFrame(&writer, it->bitmap, frameBuffer.frameW, frameBuffer.frameH, 10);
			++count;
		}
		std::cout << "Frames count:  " << count;
		GifEnd(&writer);
		isLocked = false;
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
		frameBuffer.frameH = frameH;
		frameBuffer.frameW = frameW;

		bInitialized = true;
	}

	bool isInitialized()
	{
		return bInitialized;
	}

private:
	GdiImageDumper() {}

	~GdiImageDumper()
	{
		GdiplusShutdown(gdiplusToken);
		GifEnd(&writer);
	}

	ULONG_PTR gdiplusToken = 0;
	bool bInitialized = false;
	CLSID pngClsid;
	std::string path;
	int saveIndex = 0;
	GifWriter writer;
	FrameBuffer frameBuffer;

	bool isLocked = false;
};