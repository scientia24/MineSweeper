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
	mStage.init();
    while (true) {
		Display::Show(mStage, cursor);
		auto input = _getch();
		system("cls");
		if (input != 0xe0) continue;
		auto command = _getch();
		switch (command)
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
}