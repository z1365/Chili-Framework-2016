/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
    Game( class MainWindow& wnd );
    Game( const Game& ) = delete;
    Game& operator=( const Game& ) = delete;
    void Go();
private:
    void ComposeFrame();
    void UpdateModel();
    /********************************/
    /*  User Functions              */
    void DrawBox(int x, int y, int r, int g, int b);
    

    bool IsOnScreen(int x, int y, int width, int height);
    bool IsCollided(int x, int y, int width, int height, int target_x, int target_y, int target_w, int target_h);
    /********************************/
private:
    MainWindow& wnd;
    Graphics gfx;
    /********************************/
    /*  User Variables              */

    int cursor_x = 10;
    int cursor_y = 10;

    //скорость в координатах для курсора
    int vx = 0;
    int vy = 0;
    //приращение скорости в пикселях
    int dv = 1;


    //координаты препятствий
    int barrier_0_x = 50;
    int barrier_1_x = 150;
    int barrier_2_x = 250;
    int barrier_3_x = 350;
    int barrier_0_y = 70;
    int barrier_1_y = 27;
    int barrier_2_y = 498;
    int barrier_3_y = 159;
    
    //флаги нажатия клавиш
    bool inhibitLeft = false;
    bool inhibitRight = false;
    bool inhibitUp = false;
    bool inhibitDown = false;

    // признак во что то упёрся
    bool collision = false;

    int cursor_color_r = 0;
    int cursor_color_g = 255;
    int cursor_color_b = 0;

    int barrier_color_r = 255;
    int barrier_color_g = 255;
    int barrier_color_b = 255;
    /********************************/
};