// this file will be use to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
	Position p = getscreensize();  // this function is to get the screen size of the terminal 
	if ( p.col < BARS ) // if it not get to a qualified size 
	{
		printf("Your screen size is not wide enough to display :D");
		return 1; 	
	}
	char postdata[1000] ; 
//	sprintf(postdata, "
	clearscreen(); // clear the whole screen 
	FILE *fp = fopen("test.wav", "r"); // open the wav file 
	WAVheader h = readwavhdr(fp); // read the first four lines 
	displaywavhdr(h);
	getchar(); 
	clearscreen(); 
	wavdata(h, fp);  // display data as column 
	getchar();
	fclose(fp); // close the file 
	resetcolors(); // reset color to default 
	sprintf(postdata, "row=%d&col=%d&id=e1900315&peaks=%d&maximum=%lf", p.row, p.col, peaks, max);
	sendpost(URL, postdata);
	return 0 ; 
}

