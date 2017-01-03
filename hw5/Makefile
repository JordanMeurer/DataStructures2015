# Makefile for programs in directory
#******************************************************

PROGRAMS = hw5

#******************************************************
# Parameters to control Makefile operations
#Note that the gccx cammand script must be defined

CC = gcc
GFLAGS =

#******************************************************
#Standard entire to remove files from the directories
#       tidy    --eliminate unwanted files
#       scratch -- delete derived files in prepaation for rebuild

tidy:
	rm -f, * .,* *` core a,out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

#******************************************************
# C compilations

hw5.o: hw5.c library.h
	gcc -c hw5.c
library.o: library.c library.h
	gcc -c library.c

#*****************************************************
#Executable programs

hw5: hw5.o library.o
	gcc -o hw5 hw5.o library.o
