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
    gfx(wnd)
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
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        if (!inhibitRight)
        {
            vx += 1;
            inhibitRight = true;
        }
    }
    else
    {
        inhibitRight = false;
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        if (!inhibitLeft)
        {
            vx -= 1;
            inhibitLeft = true;
        }
    }
    else
    {
        inhibitLeft = false;
    }
    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        if (!inhibitUp)
        {
            vy -= 1;
            inhibitUp = true;
        }
    }
    else
    {
        inhibitUp = false;
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        if (!inhibitDown)
        {
            vy += 1;
            inhibitDown = true;
        }
    }
    else
    {
        inhibitDown = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_SPACE))
    {
        vx = vy = 0;
    }
     if (   (x + 10 + vx >= xt && x + vx <= xt + 10) 
         && (y + 10 + vy >= yt && y + vy <= yt + 10)
        )
    {
        mainColor = { 0xFF10FF10 };
        vx = vy = 0;
    }
    else {
        mainColor = { 0xFFFFFFFF };
    }

    if ((x + vx <= gfx.ScreenWidth - 11) && (x + vx >= 0))
    {
        x += vx;
    }
    else
    {
        vx = 0;
    }
    if ((y + vy <= gfx.ScreenHeight - 11) && (y + vy >= 0))
    {
        y += vy;
    }
    else
    {
        vy = 0;
    }

    alterShape = wnd.kbd.KeyIsPressed(VK_SHIFT);


}

void Game::ComposeFrame()
{

    if (alterShape)
    {
        // ������
        // ������������ ������� �������
        gfx.PutPixel(x + 5, y + 0, mainColor);
        gfx.PutPixel(x + 5, y + 1, mainColor);
        gfx.PutPixel(x + 5, y + 2, mainColor);
        gfx.PutPixel(x + 5, y + 8, mainColor);
        gfx.PutPixel(x + 5, y + 9, mainColor);
        gfx.PutPixel(x + 5, y + 10, mainColor);

        // �������������� ������� �������
        gfx.PutPixel(x + 0, y + 5, mainColor);
        gfx.PutPixel(x + 1, y + 5, mainColor);
        gfx.PutPixel(x + 2, y + 5, mainColor);
        gfx.PutPixel(x + 8, y + 5, mainColor);
        gfx.PutPixel(x + 9, y + 5, mainColor);
        gfx.PutPixel(x + 10, y + 5, mainColor);
    }
    else {
        // ���� �������
        gfx.PutPixel(x + 0, y + 0, mainColor);
        gfx.PutPixel(x + 1, y + 0, mainColor);
        gfx.PutPixel(x + 2, y + 0, mainColor);
        gfx.PutPixel(x + 6, y + 0, mainColor);
        gfx.PutPixel(x + 7, y + 0, mainColor);
        gfx.PutPixel(x + 8, y + 0, mainColor);

        gfx.PutPixel(x + 0, y + 8, mainColor);
        gfx.PutPixel(x + 1, y + 8, mainColor);
        gfx.PutPixel(x + 2, y + 8, mainColor);
        gfx.PutPixel(x + 6, y + 8, mainColor);
        gfx.PutPixel(x + 7, y + 8, mainColor);
        gfx.PutPixel(x + 8, y + 8, mainColor);

        gfx.PutPixel(x + 8, y + 0, mainColor);
        gfx.PutPixel(x + 8, y + 1, mainColor);
        gfx.PutPixel(x + 8, y + 2, mainColor);
        gfx.PutPixel(x + 8, y + 6, mainColor);
        gfx.PutPixel(x + 8, y + 7, mainColor);

        gfx.PutPixel(x + 0, y + 1, mainColor);
        gfx.PutPixel(x + 0, y + 2, mainColor);
        gfx.PutPixel(x + 0, y + 6, mainColor);
        gfx.PutPixel(x + 0, y + 7, mainColor);
        gfx.PutPixel(x + 0, y + 8, mainColor);

    }
    // ���� ����
    gfx.PutPixel(xt + 0, yt + 0, 100,0,50);
    gfx.PutPixel(xt + 1, yt + 0, 100,0,50);
    gfx.PutPixel(xt + 2, yt + 0, 100,0,50);
    gfx.PutPixel(xt + 6, yt + 0, 100,0,50);
    gfx.PutPixel(xt + 7, yt + 0, 100,0,50);
    gfx.PutPixel(xt + 8, yt + 0, 100,0,50);

    gfx.PutPixel(xt + 0, yt + 8, 100,0,50);
    gfx.PutPixel(xt + 1, yt + 8, 100,0,50);
    gfx.PutPixel(xt + 2, yt + 8, 100,0,50);
    gfx.PutPixel(xt + 6, yt + 8, 100,0,50);
    gfx.PutPixel(xt + 7, yt + 8, 100,0,50);
    gfx.PutPixel(xt + 8, yt + 8, 100,0,50);

    gfx.PutPixel(xt + 8, yt + 0, 100,0,50);
    gfx.PutPixel(xt + 8, yt + 1, 100,0,50);
    gfx.PutPixel(xt + 8, yt + 2, 100,0,50);
    gfx.PutPixel(xt + 8, yt + 6, 100,0,50);
    gfx.PutPixel(xt + 8, yt + 7, 100,0,50);

    gfx.PutPixel(xt + 0, yt + 1, 100,0,50);
    gfx.PutPixel(xt + 0, yt + 2, 100,0,50);
    gfx.PutPixel(xt + 0, yt + 6, 100,0,50);
    gfx.PutPixel(xt + 0, yt + 7, 100,0,50);
    gfx.PutPixel(xt + 0, yt + 8, 100,0,50);
}
