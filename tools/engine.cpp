#include <iostream>
#include "../engine/screen.h"
#include <curses.h>
using namespace std;
int main()
{
	initscr();
	refresh();
	noecho();
	screen scr;
	char c;
	do
	{
		cout << scr.getObject().getObject() << endl;
		c = getch();
		if (c == '1')
			scr.setSelectedObject(1);
		if (c == '2')
			scr.setSelectedObject(2);
		if (c == '3')
			scr.setSelectedObject(3);
		if (c == '4')
			scr.setSelectedObject(4);
		if (c == '5')
			scr.setSelectedObject(5);
		if (c == 'w')
			scr.moveMouse(UP);
		if (c == 'a')
			scr.moveMouse(LEFT);
		if (c == 's')
			scr.moveMouse(DOWN);
		if (c == 'd')
			scr.moveMouse(RIGHT);
		if (c == '\n')
            		scr.insertObject();
	} while (c != 'Q');
	endwin();
}
