// this file will be use to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"

int main(void)
{
	Position cur = getscreensize();
	char postdata[1000];
	sprintf(postdata, "row=%d&col=%d&id=e1900315", cur.row, cur.col);
	sendpost(URL, postdata);
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col); 
	printf("Today we will make some animations. Press any key to continue\n");
	getchar();
	getchar(); 
	int ff, bb;
	float step = (float)cur.col/cur.row;  
	for(int i=1 ; i<=cur.row ; i++)
	{
		clearscreen();
		setfgcolor(RED);
		drawrect(i, i*3, 2, 4);
		setfgcolor(GREEN);  
		gotoXY(cur.row-i,(i-1)*step+1);
		printf("HELLO\n");
		usleep(500000);  
	}
/*	for(int i=1 ; i<21; i++)
	{
		clearscreen();
		setfgcolor(RED);
		drawrect(21-i ,i*3+60 ,2,4); 
		setfgcolor(GREEN); 
		gotoXY(i+1,i*3+60);
		printf("HELLO\n");
		usleep(500000);
	} */
	getchar(); 
	resetcolors();
	clearscreen();
	printf("color is set back to default\n");
	getchar();
/*	setfgcolor(CYAN);
	gotoXY(14, 35);
	printf("HELLO, WORLD!\n");
	getchar();
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();
	resetcolors();
	printf("This text is displayed in default color\n");
*/
}

