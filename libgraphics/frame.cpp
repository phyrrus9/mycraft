//
//  frame.cpp
//  libgraphics
//
//  Created by Ethan Laur on 6/5/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "frame.h"

/*
 class frame : public image
 {
 private:
 int startx, starty;
 int xsize, ysize;
 public:
 frame(); //creates a standard image
 frame(int x, int y); //creates an x by y frame
 void setPixel(int x, int y, colorcode c, bool o); //set (x,y) to <c,o>
 };
*/

frame::frame()
{
    xsize = 210;
    ysize = 90;
    startx = starty = 0;
}

frame::frame(int x, int y)
{
    xsize = x;
    ysize = y;
    startx = starty = 0;
    int xcenter = x/2;
    int ycenter = y/2;
    int xparent = 210/2;
    int yparent = 90/2;
    startx = xparent - xcenter;
    starty = yparent - ycenter;
}

void frame::setColor(colorcode c)
{
    blank();
    for (int y = starty; y < ysize; y++)
    {
        for (int x = startx; x < xsize; x++)
        {
            data.setPixel(x, y, c, true);
        }
    }
}

void frame::setPixel(int x, int y, colorcode c, bool o)
{
    int rx = x + startx;
    int ry = y + starty;
    data.setPixel(rx, ry, c, o);
}

image &frame::getObject()
{
    return data;
}

void frame::loadFromFile(const char * filename)
{
    data.loadFromFile(filename);
}

void frame::blank()
{
    data.blank();
}

void frame::placeImage(image &img)
{
    for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < 210; j++)
        {
            if (img.getPixel(j, i).getEnabled())
            {
                setPixel(j, i, img.getPixel(j, i).getColor(), img.getPixel(i, j).getEnabled());
            }
        }
    }
}

void frame::placeImage(image &img, int x, int y)
{
    for (int iy = y, ey = 0; iy < 90; iy++, ey++)
    {
        for (int ix = x, ex = 0; ix < 210; ix++, ex++)
        {
            if (img.getPixel(ex, ey).getEnabled())
            {
                setPixel(ix, iy, img.getPixel(ex, ey).getColor(), img.getPixel(ex, ey).getEnabled());
                //data[iy][ix] = img.getPixel(ex, ey);
            }
        }
    }
}

pixel &frame::getPixel(int x, int y)
{
    return data.getPixel(x + startx, y + starty);
}
