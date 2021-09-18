#include "Stage.hpp"

Stage::Stage(int aWidth, int aHeight) {
	mWidth = aWidth;
	mHeight = aHeight;
	mBombArray = Array();
}

bool Stage::isBomb(int x, int y) {
	return mBombArray.get(x, y);
}
