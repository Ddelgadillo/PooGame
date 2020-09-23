#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Walls.h"

class Poo
{
public:
	Poo() = default;
	Poo(Vec2& pos, Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Update(float delta);
	bool WallCollision(Walls& walls);
private:
	Vec2 mPos;
	Vec2 mVel;
	const float mWidth = 24.0f;
	const float mHeight = 24.0f;
	bool mIsEaten;
};