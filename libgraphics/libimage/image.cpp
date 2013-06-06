//
//  image.cpp
//  libimage
//
//  Created by Ethan Laur on 6/4/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "image.h"

/*
 class image
 {
 private:
 pixel data[90][210];
 public:
 image(); //default, calls blank()
 image(pixel p[90][210]); //pixel array
 image(image &old);
 void blank(); //sets all pixels to <black, off>
 void setPixel(int x, int y, colorcode c, bool o); //set (x,y) to <c,o>
 void placeImage(image &img); //places an image starting at (0,0)
 void placeImage(image &img, int x, int y); //places an image starting at (x,y)
 pixel *getData();
 pixel getPixel(int x, int y); //return pixel at (x,y)
 char *getObject(); //returns a string of the whole image
 };
 */

image::image()
{
    blank();
}

image::image(pixel p[90][210])
{
    for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < 210; j++)
            data[i][j] = p[i][j];
    }
}

image::image(image &old)
{
    for (int y = 0; y < 90; y++)
    {
        for (int x = 0; x < 210; x++)
            data[y][x] = old.getPixel(x, y);
    }
}

image::image(colorcode c)
{
    blank();
    for (int y = 0; y < 90; y++)
    {
        for (int x = 0; x < 210; x++)
        {
            setPixel(x, y, c, true);
        }
    }
}

image::image(const char * filename)
{
    loadFromFile(filename);
}

void image::loadFromFile(const char * filename)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
    {
        //blank();
        printf("Can not open!\n");
        exit(-1);
    }
    else
    {
        for (int i = 0; i < 90; i++)
        {
            for (int j = 0; j < 210; j++)
            {
                colorcode tmpc;
                bool onc;
                fscanf(f, "%d", (int *)&tmpc);
                fscanf(f, "%c", (char *)&onc);
                setPixel(j, i, tmpc, onc);
                //data[i][j].setColor(tmpc);
                //data[i][j].setEnabled(onc);
            }
        }
        fclose(f);
    }
}

void image::blank()
{
    pixel blnk(BLACK, false);
    for (int y = 0; y < 90; y++)
    {
        for (int x = 0; x < 210; x++)
            data[y][x] = blnk;
    }
}

void image::setPixel(int x, int y, colorcode c, bool o)
{
    data[y][x].setEnabled(o);
    data[y][x].setColor(c);
}

void image::placeImage(image &img)
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

void image::placeImage(image &img, int x, int y)
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

pixel * image::getData()
{
    return NULL;
}

pixel &image::getPixel(int x, int y)
{
    return data[y][x];
}

char * image::getObject()
{
    char *local = new char[399000];
    strcat(local, ""); //blank the string
    for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < 210; j++)
        {
            strcat(local, data[i][j].getObject());
        }
        strcat(local, "\r\n");
    }
    return local;
}

void image::writeObject(const char * filename)
{
    FILE *f = fopen(filename, "wb");
    if (f == NULL)
    {
        return;
    }
    else
    {
        for (int i = 0; i < 90; i++)
        {
            for (int j = 0; j < 210; j++)
            {
                fprintf(f, "%d%c", (int)data[i][j].getColor(), (char)data[i][j].getEnabled());
            }
        }
    }
    fclose(f);
}
