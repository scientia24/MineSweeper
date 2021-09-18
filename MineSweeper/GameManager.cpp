#include <iostream>
#include "GameManager.hpp"
#include "Stage.hpp"

GameManager::GameManager()
	: mStage(Stage(mWidth, mHeight))
{}

void GameManager::play() const {
	for (int i = 0; i < mHeight; i++) {
		for (int j = 0; j < mWidth; j++) {
			if (mStage.isBomb(j, i)) {
				std::cout << '*';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}