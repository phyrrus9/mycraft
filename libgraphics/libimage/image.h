//
//  image.h
//  libimage
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#ifndef __libimage__image__
#define __libimage__image__

#include <iostream>
#include "libpixel/pixel.h"

class image
{
protected:
    pixel data[90][210];
public:
    image(); //default, calls blank()
    image(pixel p[90][210]); //pixel array
    image(image &old);
    image(colorcode c); //init with a solid color
    image(const char * filename); //read image from file
    void loadFromFile(const char * filename); //look up
    void blank(); //sets all pixels to <black, off>
    void setPixel(int x, int y, colorcode c, bool o); //set (x,y) to <c,o>
    void placeImage(image &img); //places an image starting at (0,0)
    void placeImage(image &img, int x, int y); //places an image starting at (x,y)
    pixel &getPixel(int x, int y); //return pixel at (x,y)
    pixel *getData(); //NOT FOR USER USE
    char *getObject(); //returns a string of the whole image
    void writeObject(const char * filename); //write image to file
};

#endif /* defined(__libimage__image__) */
