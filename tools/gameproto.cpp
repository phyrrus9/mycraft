#include <iostream>
#include "../libgraphics/graphics.h"
#include <curses.h>
using namespace std;
int main()
{
#define FWD 0
#define UP  1
#define DOW 2
#define LEF 3
#define RIG 4
#define BAK 5
	initscr();
	refresh();
	noecho();
	image i;
	image mouse;
	image scr[4];
	image sandbox;
	char c;
	int perspective = 0;
	int selectedobj = 1;
	int mousex = 105, mousey = 45;
	rectangle r(10, 10, BLUE);
	rectangle mouseSelect(10, 10, MAGENTA);
	image grass("../images/grass.image");
	image brick("../images/brick.image");
	image obsidian("../images/obsidian.image");
	do
	{
		i.blank();
		i.placeImage(grass, 1, 1);
		i.placeImage(brick, 11, 1);
		i.placeImage(obsidian, 21, 1);
		i.placeImage(r.getObject(), 0, 0);
		i.placeImage(r.getObject(), 10, 0);
		i.placeImage(r.getObject(), 20, 0);
		i.placeImage(r.getObject(), 30, 0);
		int x = 5;
		if (selectedobj == 1)
			x = 5;
		if (selectedobj == 2)
			x = 15;
		if (selectedobj == 3)
			x = 25;
		if (selectedobj == 4)
			x = 35;
		i.setPixel(x, 5, YELLOW, true);
		mouse.blank();
		mouse.placeImage(mouseSelect.getObject(), mousex - 1, mousey - 1);
		//mouse.setPixel(mousex, mousey, MAGENTA, true);
		scr[perspective].blank();
		scr[perspective].placeImage(sandbox, 0, 0);
		scr[perspective].placeImage(i, 75, 75);
		scr[perspective].placeImage(mouse, 0, 0);
		cout << scr[perspective].getObject() << endl;
		c = getch();
		if (c == '1')
			selectedobj = 1;
		if (c == '2')
			selectedobj = 2;
		if (c == '3')
			selectedobj = 3;
		if (c == '4')
			selectedobj = 4;
		if (c == 'w')
			mousey -= 10;
		if (c == 'a')
			mousex -= 10;
		if (c == 's')
			mousey += 10;
		if (c == 'd')
			mousex += 10;
		if (c == '\n')
		{
			if (selectedobj == 1)
				sandbox.placeImage(grass, mousex, mousey);
			if (selectedobj == 2)
				sandbox.placeImage(brick, mousex, mousey);
			if (selectedobj == 3)
				sandbox.placeImage(obsidian, mousex, mousey);
			if (selectedobj == 4)
			{
				for (int sx = 0; sx < 10; sx++)
				{
					for (int sy = 0; sy < 10; sy++)
					{
						sandbox.setPixel(mousex + sx, mousey + sy, BLACK, false);
					}
				}
			}
		}		
/*		mousey = mousey >= 90 ? 90 : mousey;
		mousex = mousex < 0 ? 0 : mousex;
		mousey = mousey >= 210 ? 210 : mousey;
		mousey = mousey < 0 ? 90 : mousex;
*/	} while (c != 'Q');
	endwin();
}
