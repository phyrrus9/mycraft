//
//  pixel.cpp
//  libpixel
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "pixel.h"

/*
 class pixel
 {
 private:
 colorcode color;
 bool on;
 public:
 pixel(); //default to black, off
 pixel(colorcode c); //color on
 pixel(colorcode c, bool o); //color <on/off>
 void setEnabled(bool o); //toggle
 colorcode getColor();
 bool getEnabled();
 char * getObject(); //gets a printable string
 };
*/

pixel::pixel()
{
    color = BLACK;
    on = false;
}

pixel::pixel(colorcode c)
{
    color = c;
    on = false;
}

pixel::pixel(colorcode c, bool o)
{
    color = c;
    on = o;
}

pixel::pixel(pixel &p)
{
    color = p.getColor();
    on = p.getEnabled();
}

void pixel::setEnabled(bool o)
{
    on = o;
}

void pixel::setColor(colorcode c)
{
    color = c;
}

colorcode pixel::getColor()
{
    return color;
}

bool pixel::getEnabled()
{
    return on;
}

const char * pixel::getObject()
{
    if (on == false)
        return CRESET "  ";
    switch (color)
    {
        case BLACK:
            return CBLACK;
            break;
        case BLUE:
            return CBLUE;
            break;
        case GREEN:
            return CGREEN;
            break;
        case RED:
            return CRED;
            break;
        case WHITE:
            return CWHITE;
            break;
        case CYAN:
            return CCYAN;
            break;
        case MAGENTA:
            return CMAGEN;
            break;
        case YELLOW:
            return CYELLO;
            break;
        case SPECIAL:
            return CSPEC;
            break;
    }
    return CRESET "  ";
}

