#include "FrameBuffer.h"
#include <iostream>
#include <chrono>
#include "freerdp/log.h"

FrameBuffer::FrameBuffer(int w, int h) :
	frameW(w), frameH(h)
{
	if (w == 0 || h == 0) {
		throw std::invalid_argument("Width and Height can not be 0");
	}
};

void FrameBuffer::add(LICE_pixel * buf)
{
	// 4 bytes per pixel
	size_t size = frameW * frameH;

	Frame frame;
	frame.timestamp = std::chrono::system_clock::now();

	frame.bitmap = std::make_shared<LICE_MemBitmap>(frameW, frameH, 0);
	std::copy(buf, buf + size, frame.bitmap->getBits());

	frames.push_back(frame);

	//Keep only frames within last historySize seconds
	auto getDelta = [&]() {
		std::chrono::duration<double> elapsed_seconds = frames.back().timestamp - frames.front().timestamp;
		return elapsed_seconds.count();
	};

	auto secondsDelta = getDelta();

	//TODO IMPORTANT:: change to seconds delta when the size of buffer is optimized
	while (/*secondsDelta > historySize &&*/ frames.size() > 69) {
		frames.pop_front();
		secondsDelta = getDelta();
	}
}

const Frame & FrameBuffer::get(int index)
{
	auto it = std::next(frames.begin(), index);
	if (it != frames.end()) {
		return *it;
	}
	return Frame();
}

std::deque<Frame>::iterator FrameBuffer::begin()
{
	return frames.begin();
}

std::deque<Frame>::iterator FrameBuffer::end()
{
	return frames.end();
}

int FrameBuffer::getWidth()
{
	return frameW;
}

int FrameBuffer::getHeight()
{
	return frameH;
}

/*
=======================================================================
					PERFORMANCE MEASURE DRAFT
=======================================================================

std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//...do something.....
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
std::cout << "bitmap.resize and std::copy took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
	<< "ms"<< std::endl;

//To write log in release
WLog_INFO("", "%s%d", "bitmap.resize and std::copy took :", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

*/