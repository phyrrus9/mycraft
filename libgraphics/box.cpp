//
//  box.cpp
//  libgraphics
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "box.h"

/*
 class box //make a square box
 {
 private:
 int size;
 colorcode color;
 image data;
 public:
 box(); //create a 1x1 black box
 box(int s); //create a sxs black box
 box(colorcode c); //create a 1x1 c box
 box(int s, colorcode c); //create a sxs c box
 box(box &old); //copy constructor
 void setSize(int s); //resize box to sxs
 void setColor(colorcode c); //change color
 void setVisible(bool v); //sets the flag on the pixels
 int getSize();
 colorcode getColor();
 bool isVisible();
 };
*/

box::box()
{
    visible = true;
    box(BLACK);
}

box::box(int s)
{
    visible = true;
    box(s, BLACK);
}

box::box(colorcode c)
{
    visible = true;
    color = c;
    //data.blank();
    //size = 1;
    //data.setPixel(0, 0, color, true);
    box(size, color);
}

box::box(int s, colorcode c)
{
    visible = true;
    color = c;
    size = s;
    data.blank();
    for (int i = 0; i < size; i++)
    {
        data.setPixel(i, 0, color, true);
        data.setPixel(i, size, color, true);
        data.setPixel(0, i, color, true);
        data.setPixel(size, i, color, true);
    }
    data.setPixel(size, size, color, true);
}

box::box(box &old)
{
    color = old.getColor();
    size = old.getSize();
    setVisible(old.isVisible());
    box(size, color);
}

void box::setSize(int s)
{
    size = s;
    box(size, color);
}

void box::setColor(colorcode c)
{
    color = c;
    box(size, color);
}

void box::setVisible(bool v)
{
    visible = v;
    if (v == false)
        data.blank();
    else
        box(size, color);
}

int box::getSize()
{
    return size;
}

colorcode box::getColor()
{
    return color;
}

image &box::getObject()
{
   return data;
}

bool box::isVisible()
{
    return visible;
}
