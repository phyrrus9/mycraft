//
//  frame.h
//  libgraphics
//
//  Created by Ethan Laur on 6/5/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "externals.h"

#ifndef __libgraphics__frame__
#define __libgraphics__frame__

#include <iostream>

class frame
{
private:
    int startx, starty;
    int xsize, ysize;
    image data;
public:
    frame(); //creates a standard image
    frame(int x, int y); //creates an x by y frame
    void setColor(colorcode c); //set color of entire frame
    void setPixel(int x, int y, colorcode c, bool o); //set (x,y) to <c,o>
    image &getObject(); //return data
    void loadFromFile(const char * filename); //look up
    void blank(); //sets all pixels to <black, off>
    void placeImage(image &img); //places an image starting at (0,0)
    void placeImage(image &img, int x, int y); //places an image starting at (x,y)
    pixel &getPixel(int x, int y); //return pixel at (x,y)
    pixel *getData(); //NOT FOR USER USE
    void writeObject(const char * filename); //write image to file
};

#endif /* defined(__libgraphics__frame__) */
