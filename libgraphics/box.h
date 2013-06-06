//
//  box.h
//  libgraphics
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "externals.h"

#ifndef __libgraphics__box__
#define __libgraphics__box__

#include <iostream>

class box //make a square box
{
private:
    int size;
    colorcode color;
    image data;
    bool visible;
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
    image &getObject();
};

#endif /* defined(__libgraphics__box__) */
