#pragma once
#include "Vec2.h"
#include "Graphics.h"

class ToiletPaper
{
public:
	ToiletPaper() = default;
	ToiletPaper(Vec2& pos);
	void Draw(Graphics& gfx);
private:
	Vec2 mPos;
	static constexpr float mWidth = 35.0f;
	static constexpr float mHeight = 19.0f;
};