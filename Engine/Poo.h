#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Walls.h"
#include "Dude.h"

class Poo
{
public:
	Poo() = default;
	Poo(Vec2& pos, Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Update(float delta, Walls& wall);
	bool WallCollision(Walls& walls);
	bool DudeCollision(const Dude& dude);
	void SetIsEaten(bool isEaten);
private:
	Vec2 mPos;
	Vec2 mVel;
	bool mIsEaten;
	static constexpr float mWidth = 24.0f;
	static constexpr float mHeight = 24.0f;
};