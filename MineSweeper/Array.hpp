#pragma once
class Array {
public:
	Array();
	bool get(int x, int y) { return mArray[x + y * (mHeight - 1)]; }
	void set(int x, int y, bool t) { mArray[x + y * (mHeight - 1)] = t; }

private:
	int mWidth;
	int mHeight;
	bool mArray[100];
};
