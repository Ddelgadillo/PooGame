#include "Walls.h"

Walls::Walls(float left, float right, float top, float bottom) :
	mLeft(left),
	mRight(right),
	mTop(top),
	mBottom(bottom)
{}

Walls::Walls(Vec2& topLeft, Vec2& bottomRight) :
	Walls(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{}
