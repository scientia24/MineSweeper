#include <random>
#include "Stage.hpp"

Stage::Stage(int aWidth, int aHeight)
	: mWidth(aWidth)
	, mHeight(aHeight)
{
	mBombArray = Array<int>();
	mOpenArray = Array<bool>();
	mFlagArray = Array<bool>();

	for (int i = 0; i < aHeight; i++) {
		for (int j = 0; j < aWidth; j++) {
			mBombArray.set(j, i, 0);
			mOpenArray.set(j, i, false);
			mFlagArray.set(j, i, false);
		}
	}
}

void Stage::init(int bombNum, const Vector2& cursor) {
	// 爆弾をランダムにセット
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(0, mWidth * mHeight - 1);
	int count = 0;
	while (count < bombNum) {
		auto num = distr(eng);
		// 既に爆弾がある場所と最初に開けたマスに爆弾は置かない
		if (!(isBomb(num) || num == cursor.x + cursor.y * mWidth)) {
			mBombArray.set(num, -1);
			++count;
		}
	}
	
	// 周囲のマスにある爆弾の個数を保存
	for (int i = 0; i < mHeight; i++) {
		for (int j = 0; j < mWidth; j++) {
			if(!isBomb(j,i)) mBombArray.set(j, i, countAroundBomb(j, i));
		}
	}
}

bool Stage::isBomb(int num) const {
	return inStage(num) && (mBombArray.get(num) == -1);
}

bool Stage::isBomb(int x, int y) const {
	return inStage(x, y) && (mBombArray.get(x, y) == -1);
}

bool Stage::isOpen(int x, int y) const {
	return inStage(x, y) && mOpenArray.get(x, y);
}

bool Stage::isFlag(int x, int y) const {
	return inStage(x, y) && mFlagArray.get(x, y);
}

void Stage::open(int x, int y) {
	if (!inStage(x, y) || isFlag(x, y)) return;
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

void Stage::open(const Vector2& vec) {
	open(vec.x, vec.y);
}

void Stage::flag(int x, int y) {
	if (!inStage(x, y) || isOpen(x, y)) return;
	mFlagArray.set(x, y, !mFlagArray.get(x, y));
}

void Stage::flag(const Vector2& vec) {
	flag(vec.x, vec.y);
}

bool Stage::inStage(int num) const {
	return 0 <= num && num < mWidth* mHeight;
}

bool Stage::inStage(int x, int y) const {
	return 0 <= x && x < mWidth && 0 <= y && y < mHeight;
}

int Stage::getAroundBombNum(int x, int y) const {
	if (!inStage(x, y)) return 0;
	return mBombArray.get(x, y);
}

void Stage::openAllCell() {
	for (int i = 0; i < mHeight; i++) {
		for (int j = 0; j < mWidth; j++) {
			mOpenArray.set(j, i, true);
		}
	}
}

int Stage::getFlagNum() const {
	int count = 0;
	for (int i = 0; i < mHeight; i++) {
		for (int j = 0; j < mWidth; j++) {
			if (mFlagArray.get(j, i)) ++count;
		}
	}
	return count;
}

int Stage::countAroundBomb(int x, int y) const {
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (j == 0 && i == 0) continue;
			if (isBomb(x + j, y + i)) count++;
		}
	}
	return count;
}
