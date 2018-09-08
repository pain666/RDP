#pragma once
#include <vector>
#include <array>
#include <chrono>
#include <deque>
#include <memory>
#include <lice.h>

struct Frame
{
	std::chrono::system_clock::time_point timestamp;
	std::shared_ptr<LICE_IBitmap> bitmap;
};

struct Pixel
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

class FrameBuffer
{
public:
	FrameBuffer(int w = 0, int h = 0);

	void add(LICE_pixel * buf);
	const Frame& get(int index);

	std::deque<Frame>::iterator begin();
	std::deque<Frame>::iterator end();

	int getWidth();
	int getHeight();

private:
	/// History size in seconds
	double historySize = 1;
	int frameW;
	int frameH;
	std::deque<Frame> frames;
};



