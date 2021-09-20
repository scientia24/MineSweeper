#include <iostream>
#include "Display.hpp"

void Display::Show(const Stage& aStage, const Vector2& aCursor) {
	const std::string fullNum[] = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10" };
	const std::string explainSentence[] = { "方向キー: カーソル移動", "A: マス目を開く", "F: 旗を立てる" };
	constexpr auto expLine = 3;
	constexpr auto backDefaultColor = "\x1b[49m";
	constexpr auto backWhite = "\x1b[47m";
	constexpr auto backYellow = "\x1b[43m";

	constexpr auto literalDefaultColor = "\x1b[39m";
	constexpr auto literalWhite = "\x1b[30m";
	constexpr auto literalRed = "\x1b[31m";
	constexpr auto literalGreen = "\x1b[32m";
	constexpr auto literalYellow = "\x1b[33m";
	constexpr auto literalBlue = "\x1b[34m";

	std::string str = "";
	str += "  ｜";

	for (int i = 0; i < aStage.getWidth(); i++) {
		str += fullNum[i];
	}
	str += "\n";

	str += "―┼";
	for (int i = 0; i < aStage.getWidth() + 1; i++) {
		str += "―";
	}

	str += "\n";

	for (int i = 0; i < aStage.getHeight(); i++) {
		str += fullNum[i];
		str += "｜";
		for (int j = 0; j < aStage.getWidth(); j++) {
			if (j == aCursor.x && i == aCursor.y) {
				str += "□";
			}
			else {
				if (aStage.isFlag(j, i)) {
					str += backYellow;
					str += literalWhite;
					str += " F";
				}
				else if (!aStage.isOpen(j, i)) {
					str += backWhite;
					str += "  ";
				}
				else {
					if (aStage.isBomb(j, i)) {
						str += literalRed;
						str += " *";
					}
					else {
						int bombNum = aStage.getBombNum(j, i);
						switch (bombNum)
						{
						case 1:
							str += literalBlue;
							break;
						case 2:
							str += literalGreen;
							break;
						case 3:
							str += literalYellow;
							break;
						case 4:
							str += literalRed;
							break;
						default:
							break;
						}
						str += (bombNum == 0 ? "  " : fullNum[bombNum - 1]);
					}
				}
				str += backDefaultColor;
				str += literalDefaultColor;
			}
		}
		if (i < expLine) {
			str += "    ";
			str += explainSentence[i];
		}
		str += "\n";
	}
	std::cout << str;
}