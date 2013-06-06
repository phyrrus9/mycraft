//
//  screen.h
//  libmycraft
//
//  Created by Ethan Laur on 6/6/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "../libgraphics/graphics.h"
#include "../libgraphics/libperspective/perspective.h"

#ifndef __libmycraft__screen__
#define __libmycraft__screen__

#include <iostream>

typedef enum { LEFT, RIGHT, UP, DOWN } moveDirection;

class screen
{
protected:
    image i;
	image mouse;
	image scr;
	perspective sandbox;
    image *grass;//("../images/grass.image");
	image *brick;//("../images/brick.image");
	image *obsidian;//("../images/obsidian.image");
    rectangle *toolBox;//(10, 10, BLUE);
	rectangle *mouseSelect;//(10, 10, MAGENTA);
    int mousex, mousey;
    int selectedObject;
public:
    screen(); //default
    screen(screen &old); //copy
    void draw(); //redraw objects
    void insertObject(); //inserts selected object at current mousepoint
    void moveMouse(moveDirection d); //moves the pointer
    void setSelectedObject(int o); //sets obj
    image &getObject(); //return a compiled screen
};

#endif /* defined(__libmycraft__screen__) */
