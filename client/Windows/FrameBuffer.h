#pragma once
#include <vector>
#include <array>
#include <chrono>
#include <deque>

struct Frame
{
	std::chrono::system_clock::time_point timestamp;
	uint8_t* bitmap = nullptr;

	~Frame() {
		if (bitmap) {
			delete[] bitmap;
		}
	}
};

class FrameBuffer
{
public:
	FrameBuffer(int w = 0, int h = 0, int historySize = 1);

	void add(uint8_t*);
	const Frame& get(int index);

	std::deque<Frame>::iterator begin();
	std::deque<Frame>::iterator end();

	int frameW;
	int frameH;

private:
	/// History size in seconds
	int historySize;
	std::deque<Frame> frames;
};



