#include <iostream>
#include "Display.hpp"

void Display::Show(Stage aStage, Vector2 aCursor) {
	const std::string fullNum[] = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10" };
	std::cout << "  ";

	for (int i = 0; i < aStage.getWidth(); i++) {
		std::cout << fullNum[i];
	}
	std::cout << std::endl;

	for (int i = 0; i < aStage.getHeight(); i++) {
		std::cout << fullNum[i];
		for (int j = 0; j < aStage.getWidth(); j++) {
			if (j == aCursor.x && i == aCursor.y) {
				std::cout << " ";
			}
			else {
				if (aStage.isFlag(j, i)) {
					std::cout << " F";
				}
				else if (!aStage.isOpen(j, i)) {
					std::cout << "  ";
				}
				else {
					if (aStage.isBomb(j, i)) {
						std::cout << " *";
					}
					else {
						int bombNum = aStage.getBombNum(j, i);
						std::cout << (bombNum == 0 ? " ." : fullNum[bombNum - 1]);
					}
				}
			}
		}
		std::cout << std::endl;
	}
}