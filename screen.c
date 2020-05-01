
// The file contains functions to manipulate screens, such as foreground
// color, background color, clear screen, restore default settings, etc.
// In this 
#include <stdio.h> 
#include "screen.h" // contains constants used in this file

void setfgcolor(int fg) // this is set the fore ground color 
{
	printf("%c[1;%dm", ESC, fg);
}

void setbgcolor(int bg) // this is the background color 
{
	printf("%c[1;%dm",ESC, bg);
}

void setcolors(int fg, int bg) // now we combine both in 1 function
{
	setfgcolor(fg);
	setbgcolor(bg); 
}

void clearscreen(void) // function to clear the screen 
{
	printf("%c[2J", ESC);
}

void resetcolors(void) // function to reset color back to default 
{
	printf("%c[0m", ESC);
}

void gotoXY(int row, int col) // this function is to send text, block or anything to a specific coordinate 
{
	printf("%c[%d;%dH", ESC, row, col);
}

void drawbar(int col, int height) // this function is used to draw bar with specific height and with specific width 
{
	int i;
	for(i=1; i<=height; i++)
	{
		gotoXY(40-i, col);
#ifdef UNICODE
		printf("%s", BAR);
#else		
		printf("%c", '#');
#endif
	}
}
void drawrect(int row, int col, int height, int width) // this function is to draw a rectangle by existing bar 
{
	int i, j; // loop control variables
	for(i = row; i < row + height; i++)
	{
		for(j=col; j< col+width; j++)
		{
			gotoXY(i,j); 
#ifdef UNICODE
			printf("%s",BAR);
#else
			printf("%c",'#');
#endif			
		}
		printf("\n");
	}
}

Position getscreensize(void) // this function is to get the screen size 
{
	Position p; 
	int r, c; 
	char ret[100] = "\0";
	gotoXY(999,999); 
	printf("%c[6n", ESC);
	scanf("%s", ret); 
#ifdef DEBUG
	printf("%s\n", ret); 
#endif
#include <string.h>
	if(strlen(ret)>0)
	{
		char dum; //dummy char to consume those letter
		int r, c; 
		sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum); 
		p.row = r;
		p.col = c;  
	}
	else
	{
	p.row = 0;
	p.col = 0;
	}
	return p; 
}

