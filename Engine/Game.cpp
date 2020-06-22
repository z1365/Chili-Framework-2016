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
    //нажали вправо
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        //если еще не нажимали, ускориться
        if (!inhibitRight)
        {
            vx += dv;
            inhibitRight = true;
        }
    }
    else
    {
        //отцепили вправо - встать
        inhibitRight = false;
        //vx = 0;
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        if (!inhibitLeft)
        {
            vx -= dv;
            inhibitLeft = true;
        }
    }
    else
    {
        inhibitLeft = false;
        //vx = 0;
    }
    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        if (!inhibitUp)
        {
            vy -= dv;
            inhibitUp = true;
        }
    }
    else
    {
        inhibitUp = false;
        //vy = 0;
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        if (!inhibitDown)
        {
            vy += dv;
            inhibitDown = true;
        }
    }
    else
    {
        inhibitDown = false;
        //vy = 0;
    }
    // на пробел резкий тормоз
    if (wnd.kbd.KeyIsPressed(VK_SPACE))
    {
        vx = vy = 0;
    }
    // проверка коллизии
    if (
        IsCollided(cursor_x, cursor_y, 8, 8, barrier_0_x, barrier_0_y, 8, 8)
        || IsCollided(cursor_x, cursor_y, 8, 8, barrier_1_x, barrier_1_y, 8, 8)
        || IsCollided(cursor_x, cursor_y, 8, 8, barrier_2_x, barrier_2_y, 8, 8)
        || IsCollided(cursor_x, cursor_y, 8, 8, barrier_3_x, barrier_3_y, 8, 8)
        )
    {
        barrier_color_r = 0;
        barrier_color_g = 0;
        barrier_color_b = 255;
        cursor_color_r = 255;
        cursor_color_g = 0;
        cursor_color_b = 0;
    }
    else {
        barrier_color_r = 255;
        barrier_color_g = 255;
        barrier_color_b = 255;
        cursor_color_r = 0;
        cursor_color_g = 255;
        cursor_color_b = 0;
    }
    //не выезжать за экран
    if (IsOnScreen(cursor_x + vx, cursor_y + vy, 8, 8))
    {
        cursor_x += vx;
        cursor_y += vy;
    }
    else
    {
        vx = vy = 0;
    }
    
}

void Game::ComposeFrame()
{
    // отрисую барьеры
    DrawBox(barrier_0_x, barrier_0_y, barrier_color_r, barrier_color_g, barrier_color_b);
    DrawBox(barrier_1_x, barrier_1_y, barrier_color_r, barrier_color_g, barrier_color_b);
    DrawBox(barrier_2_x, barrier_2_y, barrier_color_r, barrier_color_g, barrier_color_b);
    DrawBox(barrier_3_x, barrier_3_y, barrier_color_r, barrier_color_g, barrier_color_b);

    // отрисую курсор
    DrawBox(cursor_x, cursor_y, cursor_color_r, cursor_color_g, cursor_color_b);
}
/// <summary>
/// Рисует прицел в виде крадратика на заданных координатах, заданным цветом
/// </summary>
/// <param name="x">координата X</param>
/// <param name="y">координата Y</param>
/// <param name="r">красный (0..255)</param>
/// <param name="g">зеленый (0..255)</param>
/// <param name="b">синий (0..255)</param>
void Game::DrawBox( int x, int y, int r, int g, int b)
{
    gfx.PutPixel(x + 0, y + 0, r, g, b);
    gfx.PutPixel(x + 1, y + 0, r, g, b);
    gfx.PutPixel(x + 2, y + 0, r, g, b);
    gfx.PutPixel(x + 6, y + 0, r, g, b);
    gfx.PutPixel(x + 7, y + 0, r, g, b);
    gfx.PutPixel(x + 8, y + 0, r, g, b);

    gfx.PutPixel(x + 0, y + 8, r, g, b);
    gfx.PutPixel(x + 1, y + 8, r, g, b);
    gfx.PutPixel(x + 2, y + 8, r, g, b);
    gfx.PutPixel(x + 6, y + 8, r, g, b);
    gfx.PutPixel(x + 7, y + 8, r, g, b);
    gfx.PutPixel(x + 8, y + 8, r, g, b);

    gfx.PutPixel(x + 8, y + 0, r, g, b);
    gfx.PutPixel(x + 8, y + 1, r, g, b);
    gfx.PutPixel(x + 8, y + 2, r, g, b);
    gfx.PutPixel(x + 8, y + 6, r, g, b);
    gfx.PutPixel(x + 8, y + 7, r, g, b);

    gfx.PutPixel(x + 0, y + 1, r, g, b);
    gfx.PutPixel(x + 0, y + 2, r, g, b);
    gfx.PutPixel(x + 0, y + 6, r, g, b);
    gfx.PutPixel(x + 0, y + 7, r, g, b);
    gfx.PutPixel(x + 0, y + 8, r, g, b);
}

bool Game::IsOnScreen(int x, int y, int width, int height)
{
    return !(x <= 0 || y <= 0 || x + width + 1 > gfx.ScreenWidth || y + height + 1 > gfx.ScreenHeight);
}

bool Game::IsCollided(int x, int y, int width, int height, int target_x, int target_y, int target_w, int target_h)
{
    return !(target_x > x + width
        || target_y > y + height
        || x > target_x + target_w
        || y > target_y + target_h
        );
}
