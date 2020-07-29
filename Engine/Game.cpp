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
#include"Specialeffect.h"
#include"Vec2.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ft()
{
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
	float dt = ft.Mark();
	Vec input(0.0f,0.0f);
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		 input=Vec(1.0f, 0);
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		 input = Vec(-1.0f, 0);
	else if (wnd.kbd.KeyIsPressed(VK_UP))
		 input = Vec(0, -1.0f);
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		 input = Vec(0, 1.0f);


	link.update(dt, input);


}

void Game::ComposeFrame()
{
	rd.DrawRoad(gfx);
	writer.printString("a", gfx, rd.Getcity1());
	writer.printString("b", gfx, rd.Getcity2());
	link.Draw(gfx);
	
	

}