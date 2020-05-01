#appdev for I-IT1N1&2
-------------------------------------------------
-------------Application Development 2020--------
-------------------------------------------------

This project is made in course "Application Development 2020"
for us to understand what tools and measures will be used in 
an software application development.

List of contents
1.Configuration instructions
2.Installation instructions
3.Operating instructions
4.File manifest
5.Copyright and licensing information
6. Contact information
7. Credits and acknowledgements

1. Configuration instructions
	In order to run this set of file, what we need is an executed terminal such as Putty or Kitty ( preferable Linux)

2. Installation instructions
	Here are the following steps to install the application using Linux terminal:
	*Check if your terminal already have git, else type " git --version "
	*If you dont have git, then type " install git"
	*Then duplicate the repository by " git clone https://github.com/LIWKaguya/appdev
	*Now you can change the directory to appdev ( simply by " cd appdev" ) 
	*Simply type " make " and let the program do its work
	Simple right ? :D   

3.Operating instructions
	So here are the command you can use to execute the program:
	* In order to run the program, simply type "make" 
	* If you want to delete the executable program ( .o file ), then type "make clean"
	* If you compile the program in suscess ( it should be ), then type "./sound" and watch the program display the result 
	* If you are satistfied with the result, and want to make a tar file ( or a zip ), you can type "make zip"
	Simple right ? :D

4. File manifest
	We should list all the files of this application at here with short descriptions

	List of diles:
	README.md			this file.
	screen.c		contains screen manipulations functions
	screen.h		contains constant definitions and function 
					declarations at screen.c 
	testcurl.c 		contains the code which can send information to specific
					php page
	makefile 		contains the shorter version for the gcc and others command
					such as rm and tar
	testscreen.c 	this contains alot of animations and function that we can play and 
					manipulate it alongside with screen.c 
	comm.c 			contains code for the posting and responding to a specific 
					php server or website 
	comm.h 			contains constant definitions and function declarations
					at comm.c
	sound.c			here we take in the .wav files in order to dissect into parts and 
					take a closer look at where is the peaks, the maximum decibel, .etc
	sound.h			contains constant definitions and function of sound.c
	main.c 			use to execute sound.c and display figure of decibels as well as 
					showing the peaks and related information to specific .wav file
	sound.php		This file is to uploading some specific information such as the
					peaks and the maximum value of the input wav file 
5. Licenses and  Copyright 
	This application follows GPLv2 copyright. 

6. Contact information
	Facebook : Tanaka Shiro
	Github : https://github.com/LIWKaguya
	Email: hungle120901@gmail.com or leduyhung1973@gmail.com
7.Credit and Acknowledgements
	Here the project is done by Le Hung e1900315 under the supervision of doc Gao Chao of VAMK
