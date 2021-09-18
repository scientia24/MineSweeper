#include "Stage.hpp"

Stage::Stage(int aWidth, int aHeight) {
	mWidth = aWidth;
	mHeight = aHeight;
	mBombArray = Array<bool>();
	mOpenArray = Array<bool>();
}

void Stage::init() {
	mBombArray.set(2, 2, true);
}

bool Stage::isBomb(int x, int y) const {
	return mBombArray.get(x, y);
}

bool Stage::isOpen(int x, int y) const {
	return mOpenArray.get(x, y);
}

void Stage::open(int x, int y) {
	mOpenArray.set(x, y, true);
}

void Stage::open(Vector2 vec) {
	open(vec.x, vec.y);
}

bool Stage::inStage(int x, int y) const {
	return 0 <= x && x < mWidth && 0 <= y && y < mHeight;
}
