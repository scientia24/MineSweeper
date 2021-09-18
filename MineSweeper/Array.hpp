#pragma once
template <typename T>
class Array {
public:
	Array();
	T get(int x, int y) const { return mArray[x + y * mWidth]; }
	void set(int x, int y, T t) { mArray[x + y * mWidth] = t; }

private:
	int mWidth;
	int mHeight;
	T mArray[100];
};
