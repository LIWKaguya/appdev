#In this section we should give users information of how to run this application, e.g., what command-line arguments can be given and what do they mean
OBJ = screen.o main.o comm.o sound.o 
APPNAME = sound

#linking rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl -lm

#compling rule 
%.o : %.c
	gcc -c -o $@ $<

#cleaning rule 
clean : 
	rm $(APPNAME) $(OBJ) 

#archiving rule 
zip :
	tar cf screen.tar *.c *.h makefile 



