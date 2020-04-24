// this file will be use to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
	Position p = getscreensize();
	if ( p.col < BARS )
	{
		printf("Your screen size is not wide enough to display :D");
		return 1; 	
	}
	char postdata[1000] ; 
//	sprintf(postdata, "
	clearscreen();
	FILE *fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	getchar(); 
	clearscreen(); 
	wavdata(h, fp);  
	getchar();
	fclose(fp);
	resetcolors();
	sprintf(postdata, "row=%d&col=%d&id=e1900315&peaks=%d&maximum=%lf", p.row, p.col, peaks, max);
	sendpost(URL, postdata);
	return 0 ; 
}

