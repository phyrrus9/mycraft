//
//  rectangle.cpp
//  libgraphics
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "rectangle.h"

/*
 class rectangle //make a rect
 {
 private:
 int xsize, ysize;
 colorcode color;
 image data;
 bool visible;
 public:
 rectangle(); //create a 1x1 black rect
 rectangle(int x, int y); //create a xXy black box
 rectangle(colorcode c); //create a 1x1 c box
 rectangle(int x, int y, colorcode c); //create a xXy c box
 rectangle(rectangle &old); //copy constructor
 void setSize(int x, int y); //resize box to xXy
 void setColor(colorcode c); //change color
 void setVisible(bool v); //sets the flag on the pixels
 int getXSize();
 int getYSize();
 colorcode getColor();
 bool isVisible();
 image &getObject();
 };
*/

rectangle::rectangle()
{
    xsize = 1;
    ysize = 1;
    color = BLACK;
    rectangle(1, 1);
}

rectangle::rectangle(int x, int y)
{
    xsize = x;
    ysize = y;
    color = BLACK;
    rectangle(xsize, ysize, color);
}

rectangle::rectangle(colorcode c)
{
    xsize = 1;
    ysize = 1;
    color = c;
    rectangle(xsize, ysize, color);
}

rectangle::rectangle(int x, int y, colorcode c)
{
    xsize = x;
    ysize = y;
    color = c;
    data.blank();
    for (int i = 0; i < xsize; i++)
    {
        data.setPixel(i, 0, color, true);
        data.setPixel(i, ysize, color, true);
    }
    for (int i = 0; i < ysize; i++)
    {
        data.setPixel(0, i, color, true);
        data.setPixel(xsize, i, color, true);
    }
    data.setPixel(xsize, ysize, color, true);
}

rectangle::rectangle(rectangle &old)
{
    rectangle(old.getXSize(), old.getYSize(), old.getColor());
}

void rectangle::setSize(int x, int y)
{
    rectangle(x, y, color);
}

void rectangle::setColor(colorcode c)
{
    rectangle(xsize, ysize, c);
}

void rectangle::setVisible(bool v)
{
    visible = v;
    if (!v)
        data.blank();
    else
        rectangle(xsize, ysize, color);
}

int rectangle::getXSize()
{
    return xsize;
}

int rectangle::getYSize()
{
    return ysize;
}

colorcode rectangle::getColor()
{
    return color;
}

bool rectangle::isVisible()
{
    return visible;
}

image &rectangle::getObject()
{
    return data;
}
