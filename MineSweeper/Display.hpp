#pragma once
#include "Stage.hpp"
#include "Vector2.hpp"

class Display
{
public:
	static void Show(const Stage& aStage, const Vector2& aCursor);

private:
	Display();
};
