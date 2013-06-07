#include <iostream>
#include "../libgraphics/graphics.h"
#include <curses.h>
using namespace std;
int main(int argc, char * * argv)
{
	initscr();
	refresh();
	noecho();
	image p;
	if (argc >= 2)
		p.loadFromFile(argv[1]);
	char c = 0;
	int x = 0, y = 0;
	colorcode a;
	bool b;
	colorcode ta;
	bool tb;
	bool automove = true;
	while (c != 'S')
	{
		ta = p.getPixel(x, y).getColor();
		tb = p.getPixel(x, y).getEnabled();
		p.setPixel(x, y, SPECIAL, true);
		cout << p.getObject() << endl;
		c = getch();
		if (c != 'S' && c < 57)
		{
			b = true;
			if (c == '1')
				a = BLACK;
			if (c == '2')
				a = BLUE;
			if (c == '3')
				a = RED;
			if (c == '4')
				a = GREEN;
			if (c == '5')
				a = CYAN;
			if (c == '6')
				a = MAGENTA;
			if (c == 7)
				a = YELLOW;
			if (c == '8')
				b = false;
			p.setPixel(x, y, a, b);
			if (automove)
				x++;
			if (x >= 210 && automove)
			{
				x = 0;
				y++;
			}
			if (y >= 90 && automove)
				c = 'S';
		}
		else
		{
			automove = false;
			p.setPixel(x, y, ta, tb);
			if (c == 'A')
				automove = true;
			if (c == 'w')
			{
				y--;
				if (y < 0) y = 0;
			}
			if (c == 'a')
			{
				x--;
				if (x < 0) x = 0;
			}
			if (c == 's')
			{
				y++;
				if (y >= 90) y = 89;
			}
			if (c == 'd')
			{
				x++;
				if (x >= 210) y = 209;
			}
		}
	}
	endwin();
	if (argc >= 2)
		p.writeObject(argv[1]);
	else
		p.writeObject("save.image");
}
