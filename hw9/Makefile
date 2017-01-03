all: driver1 driver2

driver1: driver.o setArrayImp.o
	gcc -o driver1 driver.o setArrayImp.o

driver2: driver.o setLinkedListImp.o
	gcc -o driver2 driver.o setLinkedListImp.o

driver.o: driver.c
	gcc -c driver.c


setArrayImp.o: setArrayImp.c set.h
	gcc -c setArrayImp.c

setLinkedListImp.o: setLinkedListImp.c set.h
	gcc -c setLinkedListImp.c

