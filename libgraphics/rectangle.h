//
//  rectangle.h
//  libgraphics
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "externals.h"

#ifndef __libgraphics__rectangle__
#define __libgraphics__rectangle__

#include <iostream>

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

#endif /* defined(__libgraphics__rectangle__) */
