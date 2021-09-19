#include <iostream>
#include "Display.hpp"

void Display::Show(const Stage& aStage, const Vector2& aCursor) {
	const std::string fullNum[] = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10" };
	std::cout << "  " << "b";

	for (int i = 0; i < aStage.getWidth(); i++) {
		std::cout << fullNum[i];
	}
	std::cout << std::endl;

	std::cout << "\" << "„©";
	for (int i = 0; i < aStage.getWidth() + 1; i++) {
		std::cout << "\";
	}
	std::cout << std::endl;

	for (int i = 0; i < aStage.getHeight(); i++) {
		std::cout << fullNum[i] << "b";
		for (int j = 0; j < aStage.getWidth(); j++) {
			if (j == aCursor.x && i == aCursor.y) {
				std::cout << " ";
			}
			else {
				if (aStage.isFlag(j, i)) {
					std::cout << "\x1b[47m" << "\x1b[30m" << " F" << "\x1b[49m" << "\x1b[39m";
				}
				else if (!aStage.isOpen(j, i)) {
					std::cout << "\x1b[47m" << "  " << "\x1b[49m";
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