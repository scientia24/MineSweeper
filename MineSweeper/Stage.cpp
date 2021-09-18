#include "Stage.hpp"

Stage::Stage(int aWidth, int aHeight) {
	mWidth = aWidth;
	mHeight = aHeight;
	mBombArray = Array();
}

void Stage::init() {
	mBombArray.set(2, 2, true);
}

bool Stage::isBomb(int x, int y) const {
	return mBombArray.get(x, y);
}
