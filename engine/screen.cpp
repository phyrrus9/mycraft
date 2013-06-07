//
//  screen.cpp
//  libmycraft
//
//  Created by Ethan Laur on 6/6/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "screen.h"

screen::screen()
{
    grass = new image("..//images/grass.image");
    brick = new image("../images/brick.image");
    obsidian = new image("../images/obsidian.image");
    torch = new image("../images/torch.image");
    toolBox = new rectangle(10, 10, BLUE);
    mouseSelect = new rectangle(10, 10, MAGENTA);
    mousex = 105;
    mousey = 45;
    selectedObject = 1;
}

screen::screen(screen &old)
{
    
}

void screen::draw()
{
    i.blank();
    i.placeImage(*grass, 1, 1);
    i.placeImage(*brick, 11, 1);
    i.placeImage(*obsidian, 21, 1);
    i.placeImage(*torch, 31, 1);
    i.placeImage(toolBox->getObject(), 0, 0);
    i.placeImage(toolBox->getObject(), 10, 0);
    i.placeImage(toolBox->getObject(), 20, 0);
    i.placeImage(toolBox->getObject(), 30, 0);
    i.placeImage(toolBox->getObject(), 40, 0);
    int x = 5;
    if (selectedObject == 1)
        x = 5;
    if (selectedObject == 2)
        x = 15;
    if (selectedObject == 3)
        x = 25;
    if (selectedObject== 4)
        x = 35;
    if (selectedObject == 5)
        x = 45;
    i.setPixel(x, 5, YELLOW, true);
    mouse.blank();
    mouse.placeImage(mouseSelect->getObject(), mousex - 1, mousey - 1);
    //mouse.setPixel(mousex, mousey, MAGENTA, true);
    scr.blank();
    scr.placeImage(sandbox, 0, 0);
    scr.placeImage(i, 65, 75);
    scr.placeImage(mouse, 0, 0);
}

void screen::insertObject()
{
    if (selectedObject == 1)
        sandbox.placeImage(*grass, mousex, mousey);
    if (selectedObject == 2)
        sandbox.placeImage(*brick, mousex, mousey);
    if (selectedObject == 3)
        sandbox.placeImage(*obsidian, mousex, mousey);
    if (selectedObject == 4)
        sandbox.placeImage(*torch, mousex, mousey);
    if (selectedObject == 5)
    {
        for (int sx = 0; sx < 10; sx++)
        {
            for (int sy = 0; sy < 10; sy++)
            {
                sandbox.setPixel(mousex + sx, mousey + sy, BLACK, false);
            }
        }
    }
}

void screen::moveMouse(moveDirection d)
{
    switch (d)
    {
        case LEFT:
            mousex -= 10;
            break;
        case RIGHT:
            mousex += 10;
            break;
        case UP:
            mousey -= 10;
            break;
        case DOWN:
            mousey += 10;
            break;
    }
    if (mousey > 85)
        mousey = 85;
    if (mousey < 5)
        mousey = 5;
    if (mousex > 205)
        mousex = 205;
    if (mousex < 5)
        mousex = 5;
}

void screen::setSelectedObject(int o)
{
    selectedObject = o;
}

image &screen::getObject()
{
    draw();
    return scr;
}
