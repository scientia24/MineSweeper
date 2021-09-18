#pragma once
#include "Array.hpp"

class  Stage
{
public:
	 Stage(int aWidth, int aHeight);

	 int getWidth() { return mWidth; }
	 int getHeight() { return mHeight; }
	 bool isBomb(int x, int y);

private:
	int mWidth;
	int mHeight;
	Array mBombArray;
};

