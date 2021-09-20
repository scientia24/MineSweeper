#include <iostream>
#include "Display.hpp"

void Display::Show(const Stage& aStage, const Vector2& aCursor) {
	const std::string fullNum[] = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10" };
	constexpr auto backDefaultColor = "\x1b[49m";
	constexpr auto backWhite = "\x1b[47m";
	constexpr auto literalDefaultColor = "\x1b[39m";
	constexpr auto literalWhite = "\x1b[30m";

	std::string str = "";
	str += "  Åb";

	for (int i = 0; i < aStage.getWidth(); i++) {
		str += fullNum[i];
	}
	str += "\n";

	str += "Å\Ñ©";
	for (int i = 0; i < aStage.getWidth() + 1; i++) {
		str += "Å\";
	}
	str += "\n";

	for (int i = 0; i < aStage.getHeight(); i++) {
		str += fullNum[i];
		str += "Åb";
		for (int j = 0; j < aStage.getWidth(); j++) {
			if (j == aCursor.x && i == aCursor.y) {
				str += "Å†";
			}
			else {
				if (aStage.isFlag(j, i)) {
					str += backWhite;
					str += literalWhite;
					str += " F";
					str += literalDefaultColor;
					str += backDefaultColor;
				}
				else if (!aStage.isOpen(j, i)) {
					str += backWhite;
					str += "  ";
					str += backDefaultColor;
				}
				else {
					if (aStage.isBomb(j, i)) {
						str += " *";
					}
					else {
						int bombNum = aStage.getBombNum(j, i);
						str += (bombNum == 0 ? " ." : fullNum[bombNum - 1]);
					}
				}
			}
		}
		str += "\n";
	}
	std::cout << str;
}