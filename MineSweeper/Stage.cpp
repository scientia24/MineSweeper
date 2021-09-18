#include "Stage.hpp"
#include <iostream>
Stage::Stage(int aWidth, int aHeight) {
	mWidth = aWidth;
	mHeight = aHeight;
	mBombArray = Array<int>();
	mOpenArray = Array<bool>();

	for (int i = 0; i < aHeight; i++) {
		for (int j = 0; j < aWidth; j++) {
			mBombArray.set(j, i, 0);
			mOpenArray.set(j, i, false);
		}
	}
}

void Stage::init() {
	mBombArray.set(2, 2, -1);

	for (int i = 0; i < mHeight; i++) {
		for (int j = 0; j < mWidth; j++) {
			if(!isBomb(j,i)) mBombArray.set(j, i, getBombCount(j, i));
		}
	}
}

bool Stage::isBomb(int x, int y) const {
	return inStage(x, y) && (mBombArray.get(x, y) == -1);
}

bool Stage::isOpen(int x, int y) const {
	return inStage(x, y) && mOpenArray.get(x, y);
}

void Stage::open(int x, int y) {
	if (!inStage(x, y)) return;
	mOpenArray.set(x, y, true);

	if (mBombArray.get(x, y) != 0) return;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int dx = x + j;
			int dy = y + i;
			if (j == 0 && i == 0) continue;
			if (isBomb(dx, dy) || isOpen(dx, dy)) continue;
			open(dx, dy);
		}
	}
}

void Stage::open(Vector2 vec) {
	open(vec.x, vec.y);
}

bool Stage::inStage(int x, int y) const {
	return 0 <= x && x < mWidth && 0 <= y && y < mHeight;
}

int Stage::getBombNum(int x, int y) const {
	if (!inStage(x, y)) return 0;
	return mBombArray.get(x, y);
}

int Stage::getBombCount(int x, int y) const {
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (j == 0 && i == 0) continue;
			if (isBomb(x + j, y + i)) count++;
		}
	}
	return count;
}
