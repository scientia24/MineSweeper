#pragma once
#include "Array.hpp"

class  Stage
{
public:
	 Stage(int aWidth, int aHeight);

	 int getWidth() const { return mWidth; }
	 int getHeight() const { return mHeight; }
	 bool isBomb(int x, int y) const;

private:
	int mWidth;
	int mHeight;
	Array mBombArray;
};

