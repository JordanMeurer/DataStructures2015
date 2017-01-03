# Makefile for programs in directory
#******************************************************

PROGRAMS = hw4

#******************************************************
# Parameters to control Makefile operations
#Note that the gccx cammand script must be defined

CC = gcc
GFLAGS = 

#******************************************************
#Standard entire to remove files from the directories
#	tidy	--eliminate unwanted files
#	scratch -- delete derived files in prepaation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

#******************************************************
# C compilations

hw4.o: hw4.c randword.h
	gcc -c hw4.c
randword.o: randword.c randword.h
	gcc -c randword.c

#*****************************************************
#Executable programs

hw4: hw4.o randword.o
	gcc -o hw4 hw4.o randword.o
