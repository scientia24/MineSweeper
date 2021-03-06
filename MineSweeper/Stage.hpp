#pragma once
#include "Array.cpp"
#include "Vector2.hpp"

class  Stage
{
public:
	 Stage(int aWidth, int aHeight);

	void init(int bombNum, const Vector2& cursor);
	int getWidth() const { return mWidth; }
	int getHeight() const { return mHeight; }
	bool isBomb(int num) const;
	bool isBomb(int x, int y) const;
	bool isOpen(int x, int y) const;
	bool isFlag(int x, int y) const;
	void open(int x, int y);
	void open(const Vector2& vec);
	void flag(int x, int y);
	void flag(const Vector2& vec);
	bool inStage(int num) const;
	bool inStage(int x, int y) const;
	int getAroundBombNum(int x, int y) const;
	void openAllCell();
	int getFlagNum() const;

private:
	int countAroundBomb(int x, int y) const;
	int mWidth;
	int mHeight;
	Array<int> mBombArray;
	Array<bool> mOpenArray;
	Array<bool> mFlagArray;
};

