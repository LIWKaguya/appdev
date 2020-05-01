// this file will be use to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
	Position cur = getscreensize();
	char postdata[1000];
	sendpost(URL, postdata); // post the specific data that we want 
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col); // this is to print the row and the column size  
	printf("Today we will make some animations. Press any key to continue\n");
	getchar();
	getchar(); 
	int ff, bb;
	float step = (float)cur.col/cur.row;  
	for(int i=1 ; i<=cur.row ; i++) // this function we want  to set "HELLO" as moving diagonally from left to right 
	{
		clearscreen();
		setfgcolor(RED);
		drawrect(i, i*3, 2, 4);
		setfgcolor(GREEN);  
		gotoXY(cur.row-i,(i-1)*step+1);
		printf("HELLO\n");
		usleep(500000);  
	}
/*	for(int i=1 ; i<21; i++) // here is the 2020 project 1 part but  I commented out 
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
	FILE *fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp); // this last 3 lines just for checking header of the wav file
	fclose(fp);
	displaywavhdr(h);  
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

