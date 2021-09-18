#pragma once

class  Stage
{
public:
	 Stage(int aWidth, int aHeight);

	 int getWidth() { return mWidth; }
	 int getHeight() { return mHeight; }

private:
	int mWidth;
	int mHeight;
};

