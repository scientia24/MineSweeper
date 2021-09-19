#include <iostream>
#include <conio.h>
#include "GameManager.hpp"
#include "Stage.hpp"
#include "Display.hpp"
#include "Vector2.hpp"

GameManager::GameManager()
	: mStage(Stage(10, 10))
{}

void GameManager::play() {
	auto cursor = Vector2(0, 0);
	bool isFirst = true;
    while (!(isClear() || isGameOver())) {
		Display::Show(mStage, cursor);
		auto command = _getch();
		system("cls");

		switch (command)
		{
		case 97: // aキーでopen
			if (isFirst) mStage.init(10, cursor); // 最初にopenしたときのみ初期化
			mStage.open(cursor);
			break;
		case 102: // fキーでflag
			break;
		case 0xe0:
			if (command == 0xe0) {
				auto allowKey = _getch();
				switch (allowKey)
				{
				case 0x48:
					if (mStage.inStage(cursor.x, cursor.y - 1)) --cursor.y;
					break;
				case 0x50:
					if (mStage.inStage(cursor.x, cursor.y + 1)) ++cursor.y;
					break;
				case 0x4b:
					if (mStage.inStage(cursor.x - 1, cursor.y)) --cursor.x;
					break;
				case 0x4d:
					if (mStage.inStage(cursor.x + 1, cursor.y)) ++cursor.x;
					break;
				}
			}
			break;
		default:
			break;
		}
    }

	Display::Show(mStage, cursor);
	if (isClear()) {
		std::cout << "Congratulations!" << std::endl;
		auto command = _getch();
	}
	if (isGameOver()) {
		std::cout << "GameOver" << std::endl;
		auto command = _getch();
	}
}

bool GameManager::isClear() {
	for (int i = 0; i < mStage.getHeight(); i++) {
		for (int j = 0; j < mStage.getWidth(); j++) {
			if (!(mStage.isOpen(j, i) || mStage.isBomb(j, i))) return false;
		}
	}
	return true;
}

bool GameManager::isGameOver() {
	for (int i = 0; i < mStage.getHeight(); i++) {
		for (int j = 0; j < mStage.getWidth(); j++) {
			if (mStage.isOpen(j, i) && mStage.isBomb(j, i)) return true;
		}
	}

	return false;
}