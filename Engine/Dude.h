#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"

class Dude
{
public:
	Dude() = default;
	Dude(Vec2& pos, Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Update(Keyboard& kbd, float delta);
	bool Collision(/*Poo& poo*/) const;
	bool WallCollision();
private:
	Vec2 mPos; //Position
	Vec2 mVel; //Velocity
	float mWidth = 20.0f;
	float mHeight = 20.0f;
};