#pragma once
#include "Vec2.h"

class Walls
{
public:
	Walls() = default;
	Walls(float left, float right, float top, float bottom);
	Walls(Vec2& topLeft, Vec2& bottomRight);
public:
	float mLeft;
	float mRight;
	float mTop;
	float mBottom;
};