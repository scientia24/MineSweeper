#include <iostream>
#include "GameManager.hpp"
#include "Stage.hpp"
#include "Display.hpp"

GameManager::GameManager()
	: mStage(Stage(10, 10))
{}

void GameManager::play() {
	mStage.init();
	Display::Show(mStage);
}