/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    mDude(Vec2(400.0f, 300.0f), Vec2(60.0f, 60.0f)),
    walls(Vec2(0.0f, 0.0f), Vec2(Graphics::ScreenWidth, Graphics::ScreenHeight)),
    mTPaper(Vec2(300.0f, 200.0f)),
    mGameOver(false),
    rng(rd()),
    xDist(walls.mLeft, walls.mRight),
    yDist(walls.mTop, walls.mBottom),
    xVel(-1, 1),
    yVel(-1, 1)
{
    for (Poo& poo : poos)
    {
        poo.Init(Vec2(xDist(rng), yDist(rng)), Vec2(xVel(rng), yVel(rng)));
    }
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if (!mGameOver)
    {
        const float dt = delta.Mark();

        mDude.Update(wnd.kbd, dt);
        mDude.WallCollision(walls);

        for (Poo& poo : poos)
        {
            poo.Update(dt, walls);
            poo.SetIsEaten(poo.DudeCollision(mDude));

            if (poo.DudeCollision(mDude))
            {
                mGameOver = true;
            }
        }
    }
}

void Game::ComposeFrame()
{
    mDude.Draw(gfx);
    mTPaper.Draw(gfx);

    for (Poo& poo : poos)
    {
        poo.Draw(gfx);
    }
}
