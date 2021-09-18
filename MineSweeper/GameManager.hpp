#pragma once
#include "Stage.hpp"

class GameManager {
public:
	GameManager();
	void play() const;
private:
	Stage mStage;
	const int mWidth = 10;
	const int mHeight = 10;
};
