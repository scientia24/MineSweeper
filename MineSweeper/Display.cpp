#include <iostream>
#include "Display.hpp"

void Display::Show(Stage aStage) {
	for (int i = 0; i < aStage.getHeight(); i++) {
		for (int j = 0; j < aStage.getWidth(); j++) {
			if (aStage.isBomb(j, i)) {
				std::cout << '*';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}