#include "FrameBuffer.h"
#include <iostream>
#include <chrono>
#include "freerdp/log.h"

FrameBuffer::FrameBuffer(int w, int h, int historySize) :
	frameW(w), frameH(h), historySize(historySize) {};

void FrameBuffer::add(uint8_t* buf)
{
	// 4 bytes per pixel
	size_t size = frameW * frameH * 4;
	if (size == 0) {
		std::cerr << "Buffer add() failed: frameW or frameH is 0";
		return;
	}

	Frame frame;
	frame.timestamp = std::chrono::system_clock::now();
	frames.push_back(frame);

	auto bitmap = frames.back().bitmap;


	bitmap = new BYTE[size];
	std::copy(buf, buf + size, bitmap);


	//Keep only frames within last 15 seconds
	auto getDelta = [&]() {
		std::chrono::duration<double> elapsed_seconds = frames.back().timestamp - frames.front().timestamp;
		return elapsed_seconds.count();
	};

	auto secondsDelta = getDelta();

	while (secondsDelta > historySize && frames.size() > 2) {
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


//Performance measure draft
//std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//...do something.....
//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//std::cout << "bitmap.resize and std::copy took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
//	<< "ms"<< std::endl;

//To write log in release
//WLog_INFO("", "%s%d", "bitmap.resize and std::copy took :", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());