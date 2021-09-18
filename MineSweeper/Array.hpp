#pragma once
template <typename T>
class Array {
public:
	Array();
	T get(int x, int y) const { return mArray[x + y * (mHeight - 1)]; }
	void set(int x, int y, bool t) { mArray[x + y * (mHeight - 1)] = t; }

private:
	int mWidth;
	int mHeight;
	T mArray[100];
};
