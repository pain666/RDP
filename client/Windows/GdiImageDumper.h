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
using namespace Gdiplus;

class GdiImageDumper {
public:
	static GdiImageDumper& instance()
	{
		static GdiImageDumper s;
		return s;
	}

	void dump(HBITMAP bitmap)
	{
		if (bInitialized)
		{
			Bitmap image(bitmap, NULL);
			std::wstring imagePath = path + L"\\image" + std::to_wstring(saveIndex++) + L".png";
			image.Save(imagePath.data(), &pngClsid, NULL);
		}
		else {
			std::cerr << "Dumper is not initialized\n";
		}
	}

	void initialize(std::string str)
	{
		if (bInitialized) {
			return;
		}

		GdiplusStartupInput gdiplusStartupInput;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		CLSIDFromString(L"{557cf406-1a04-11d3-9a73-0000f81ef32e}", &pngClsid);

		struct stat s;
		if (stat(str.data(), &s) == 0 && s.st_mode & S_IFDIR)
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			path = converter.from_bytes(str);
			bInitialized = true;
		}
		else
		{
			std::cerr << "Image dump directory does not exist\n";
		}
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
	}

	ULONG_PTR gdiplusToken = 0;
	bool bInitialized = false;
	CLSID pngClsid;
	std::wstring path;
	int saveIndex = 0;
};