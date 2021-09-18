#pragma once
#include "Array.hpp"

class  Stage
{
public:
	 Stage(int aWidth, int aHeight);

	void init();
	int getWidth() const { return mWidth; }
	int getHeight() const { return mHeight; }
	bool isBomb(int x, int y) const;
	bool isOpen(int x, int y) const;
	void open(int x, int y);
	bool inStage(int x, int y) const;

private:
	int mWidth;
	int mHeight;
	Array mBombArray;
	Array mOpenArray;
};

