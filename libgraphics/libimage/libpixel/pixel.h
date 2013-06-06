//
//  pixel.h
//  libpixel
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#ifndef __libpixel__pixel__
#define __libpixel__pixel__

#include <iostream>

#define CBLACK "\033[30;40m  \033[0m"
#define CBLUE  "\033[34;44m  \033[0m"
#define CGREEN "\033[32;42m  \033[0m"
#define CRED   "\033[31;41m  \033[0m"
#define CWHITE "\033[37;47m  \033[0m"
#define CCYAN  "\033[36;46m  \033[0m"
#define CMAGEN "\033[35;45m  \033[0m"
#define CYELLO "\033[33;43m  \033[0m"
#define CRESET "\033[0m"
#define CSPEC  "\033[5m##\033[0m"

typedef enum { BLACK, BLUE, GREEN, RED, WHITE, CYAN, MAGENTA, YELLOW, SPECIAL } colorcode;

class pixel
{
private:
    colorcode color;
    bool on;
public:
    pixel(); //default to black, off
    pixel(colorcode c); //color on
    pixel(colorcode c, bool o); //color <on/off>
    pixel(pixel &p); //copy
    void setEnabled(bool o); //toggle
    void setColor(colorcode c); //change color
    colorcode getColor();
    bool getEnabled();
    const char * getObject(); //gets a printable string
};

#endif /* defined(__libpixel__pixel__) */
