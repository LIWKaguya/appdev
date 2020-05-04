#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"

//function definitions
WAVheader readwavhdr(FILE *fp) // read the wav header first 
{
	WAVheader myh; 
	fread(&myh, sizeof(myh), 1, fp); 
	return myh; 
}

void displaywavhdr(WAVheader h)
{
	for(int i=0 ; i<4 ; i++)
	{
		printf("%c", h.chunkID[i]); // printed out the ID ( should be RIFF ) 
	}
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize); // print the chunk size 
	printf("Number of channels: %d\n", h.numChannels); // print out the number of channels on the wav files
	printf("Sample rate: %d\n", h.sampleRate); // print out the sample rate 
	printf("Bits per sample: %d\n", h.bitsPerSample);  // print out bits per sample 
	// to be continued
	double duration;
	duration = (double) h.subchunk2Size/h.byteRate; // formula to calculate the length of the wav file ( duration )  
	printf("Duration: %lf seconds\n", duration);  // print out the result 
}

void wavdata(WAVheader h, FILE *fp) // read out the data 
{
	// For samoke rate 16000sps, we need to  read 2000 samples to calculate
	// "fast" decibel value. A decibel value is always calculated by RMS
	
	// (ROOT MEAN SQUARE) formula
	extern Sound sound;  
	short samples[SIZE];
	int peaks = 0 , flag = 0 ; // initialize the value of peaks and the flag as 0 
//	double array[16]; 
	int  max = 0 ; // initial the max value as 0 
	//max = array[0]; // here I want to create an array to store the max value but it turns out not a good idea 
	for(int i=0; i < BARS; i++)
	{
		fread(samples, sizeof(samples), 1, fp); 
		double sum = 0.0 ; // initialize the sum value 
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
		if (  dB > max ) // here is how you can get the maximum value 
		{
			max = (int) dB ; 
		} 
#ifdef SDEBUG // if we define the SDEBUG we print out like this way  
		printf("db[%d] = %f\n", i, dB);
#else
		if(dB > 70) // if the value of dB is bigger than 70 then we can assign that column as red 
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
			if( flag == 0) // here if the flag ( for founded peak ) = 0, we set equal to 1 cause for the case the next column is also  
			{
				flag = 1;
				peaks++; 
			}

		}
		else
		{	
			 setfgcolor(WHITE); // else if it less than 70, we marks as white 
			 if(flag == 1)
			{
				flag = 0 ; 
			}
		}
		sound.peaks = peaks; 
		sound.max = max ; 
		drawbar(i+1, (int)dB/3); // because we only want the integer value so I use (int) 
		gotoXY(1,1);
		setfgcolor(CYAN);
		printf("Sample rate:%d\n", SAMPLERATE); // display sample rate 
		gotoXY(1, 75); 
		setfgcolor(MAGENTA); 
		printf("Duration: %.3f\n", (double)  h.subchunk2Size / h.byteRate); // display duration as 3 decimal places  
		gotoXY(1, 150); 
		setfgcolor(YELLOW); 
		printf("Peaks: %d\n", peaks); // displayed peaks
		setfgcolor(BLUE);
		printf("Maximum value: %d\n", max); // displayed maximum value in all columns 
#endif
	}
}
