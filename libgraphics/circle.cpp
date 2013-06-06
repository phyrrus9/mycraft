//
//  circle.cpp
//  libgraphics
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "circle.h"

/*
 class circle //make a circle
 {
 private:
 int radius;
 colorcode color;
 image data;
 bool visible;
 public:
 circle(); //create a 1 circle
 circle(int r); //create a circle of r
 circle(colorcode c); //create a 1x1 c box
 circle(int r, colorcode c); //create a rc circle
 circle(circle &old); //copy constructor
 void setSize(int r);
 void setColor(colorcode c); //change color
 void setVisible(bool v); //sets the flag on the pixels
 int getRadius();
 colorcode getColor();
 bool isVisible();
 image &getObject();
 };
*/

circle::circle()
{
    radius = 1;
    color = BLACK;
    circle(radius, color);
}

circle::circle(int r)
{
    radius = r;
    color = BLACK;
    circle(radius, color);
}

circle::circle(colorcode c)
{
    radius = 1;
    color = c;
    circle(radius, color);
}

circle::circle(int r, colorcode c)
{
    radius = r;
    color = c;
    data.blank();
    //TODO drawing code
}

circle::circle(circle &old)
{
    radius = old.getRadius();
    color = old.getColor();
    circle(radius, color);
}

void circle::setSize(int r)
{
    radius = r;
    circle(radius, color);
}

void circle::setColor(colorcode c)
{
    color = c;
    circle(radius, color);
}

void circle::setVisible(bool v)
{
    visible = v;
    if (!visible)
        data.blank();
    else
        circle(radius, color);
}

int circle::getRadius()
{
    return radius;
}

colorcode circle::getColor()
{
    return color;
}

bool circle::isVisible()
{
    return visible;
}

image &circle::getObject()
{
    return data;
}
