#include "DoubleBuffer.hpp"

DoubleBuffer::DoubleBuffer()
	: mIsSwaped(false)
{
	mHandle1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	mHandle2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
}

DoubleBuffer::~DoubleBuffer()
{
	CloseHandle(mHandle1);
	CloseHandle(mHandle2);
}

void DoubleBuffer::write(const std::string& str) {
	auto len = static_cast<DWORD>(str.size());
	WriteConsoleA(mIsSwaped ? mHandle1 : mHandle2, str.c_str(), len, &len, 0);
	swapBuffer();
}

void DoubleBuffer::swapBuffer() {
	if ((mIsSwaped = !mIsSwaped)) {
		SetConsoleActiveScreenBuffer(mHandle1);
	}
	else {
		SetConsoleActiveScreenBuffer(mHandle1);
	}
}