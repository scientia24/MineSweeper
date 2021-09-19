#pragma once
template <typename T>
class Array {
public:
	Array();
	T get(int num) const { return mArray[num]; }
	T get(int x, int y) const { return get(x + y * mWidth); }
	void set(int num, T t) { mArray[num] = t; }
	void set(int x, int y, T t) { set(x + y * mWidth, t); }

private:
	int mWidth;
	int mHeight;
	T mArray[100];
};
