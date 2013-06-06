//
//  circle.h
//  libgraphics
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "externals.h"

#ifndef __libgraphics__circle__
#define __libgraphics__circle__

#include <iostream>

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

#endif /* defined(__libgraphics__circle__) */
