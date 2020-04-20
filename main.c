// this file will be use to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
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
}

