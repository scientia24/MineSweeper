#pragma once
#include "Stage.hpp"

class GameManager {
public:
	GameManager();
	void play();
private:
	bool isClear();
	bool isGameOver();
	Stage mStage;
};
