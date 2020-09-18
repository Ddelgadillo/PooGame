#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Poo
{
public:
	Poo() = default;
	Poo(Vec2& pos, Vec2& vel);
	void Draw(Graphics& gfx) const;
private:
	Vec2 mPos;
	Vec2 mVel;
	float mWidth;
	float mHeight;
	bool mIsEaten;
};