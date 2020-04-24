#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"

//function definitions
WAVheader readwavhdr(FILE *fp)
{
	WAVheader myh; 
	fread(&myh, sizeof(myh), 1, fp); 
	return myh; 
}

void displaywavhdr(WAVheader h)
{
	for(int i=0 ; i<4 ; i++)
	{
		printf("%c", h.chunkID[i]);
	}
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Bits per sample: %d\n", h.bitsPerSample);  
	// to be continued
	double duration;
	duration = (double) h.subchunk2Size/h.byteRate;
	printf("Duration: %lf seconds\n", duration);  
}

void wavdata(WAVheader h, FILE *fp)
{
	// For samoke rate 16000sps, we need to  read 2000 samples to calculate
	// "fast" decibel value. A decibel value is always calculated by RMS
	// (ROOT MEAN SQUARE) formula 
	short samples[SIZE];
	int peaks = 0 , flag = 0 ; 
//	double array[16]; 
	int  max = 0 ;
	//max = array[0];
	for(int i=0; i < BARS; i++)
	{
		fread(samples, sizeof(samples), 1, fp); 
		double sum = 0.0 ;
		for(int k=0 ; k<SIZE ; k++)
		{
			sum = sum + samples[k]*samples[k];
		/*	if(samples[k] > 70)
			{
			}			 
		} */
		} 
		//double dB = sqrt(sum/2000);
		double dB = 20*log10(sqrt(sum/SIZE));
		if (  dB > max )
		{
			max = (int)dB ; 
		} 
#ifdef SDEBUG
		printf("db[%d] = %f\n", i, dB);
#else
		if(dB > 70)
		{
		/*	for( int j = 1 ; j < 11 ; j++)
			{
				dB = array[j]; 
				if ( array[j] > max )
				{
					max = array[j];
				} 
			}  */
			setfgcolor(RED);
			if( flag == 0)
			{
				flag = 1;
				peaks++; 
			}

		}
		else
		{	
			 setfgcolor(WHITE);
			 if(flag == 1)
			{
				flag = 0 ; 
			}
		}
		drawbar(i+1, (int)dB/3);
		gotoXY(1,1);
		setfgcolor(CYAN);
		printf("Sample rate:%d\n", SAMPLERATE);
		gotoXY(1, 75); 
		setfgcolor(MAGENTA); 
		printf("Duration: %.3f\n", (double)  h.subchunk2Size / h.byteRate); 
		gotoXY(1, 150); 
		setfgcolor(YELLOW); 
		printf("Peaks: %d\n", peaks);
		setfgcolor(BLUE);
		printf("Maximum value: %d\n", max); 
#endif
	}
}
