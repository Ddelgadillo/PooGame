#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Walls.h"

class Dude
{
public:
	Dude() = default;
	Dude(Vec2& pos, Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Update(Keyboard& kbd, float delta);
	bool WallCollision(Walls& walls);
	Vec2 GetPosition() const;
public:
	static constexpr float mWidth = 20.0f;
	static constexpr float mHeight = 20.0f;
private:
	Vec2 mPos; //Position
	Vec2 mVel; //Velocity
};