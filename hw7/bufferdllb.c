#include<stdio.h>
#include<stdlib.h>
#include "buffer.h"
#include "strlib.h"
#include "genlib.h"

/* 2 type defs, one base and the other cells*/
typedef struct cellT{
	char ch[4];
	int ArrayCount;
	struct cellT *next;
	struct cellT *prev;
} cellT;

struct bufferCDT{
	cellT *start;
	cellT *cursor;
	/*Check previous programs*/
	int ArrayCursor;
};

bufferADT NewBuffer(void)
{
	bufferADT S;

	S = New(bufferADT);
	S->start = S->cursor = New(cellT*);
	S->start->prev = NULL;
	S->start->next = NULL;
	S->ArrayCursor = 0;
	return(S);
}
void FreeBuffer(bufferADT buffer)
{
	cellT *cp, *temp;

	cp = buffer->start;
	while(cp != NULL){
		temp = cp->next;
		FreeBlock(cp);
		cp = temp;
	}
	FreeBlock(buffer);
}
/*it does not go to the end, and uninitialized values*/
void MoveCursorForward(bufferADT buffer)
{
	cellT *temp = buffer->cursor->next;
	if(buffer->ArrayCursor == temp->ArrayCount && temp->next != NULL){
		buffer->cursor->next = temp->next;
		buffer->ArrayCursor = 0;
	}
	else if(buffer->ArrayCursor < temp->ArrayCount){
		buffer->ArrayCursor++;
	}
	else{
		printf("buffer->ArrayCursor = %d and ArrayCount = %d\n", buffer->ArrayCursor, temp->ArrayCount);
		printf("Already at the end\n");
	}
}
/*Fix this*/
void MoveCursorBackward(bufferADT buffer)
{
	cellT *temp = buffer->cursor->next;
	if(buffer->ArrayCursor == 0 && temp->prev != NULL){
		buffer->cursor->next = temp->prev;
		buffer->ArrayCursor = buffer->cursor->ArrayCount;
	}
	else if(buffer->ArrayCursor == 0 && temp->prev == NULL){
		printf("Already at the beginning");
	}
	else{
		buffer->ArrayCursor--;
	}
}
void MoveCursorToStart(bufferADT buffer)
{
	buffer->cursor->next = buffer->start->next;
	buffer->ArrayCursor = 0;
}
void MoveCursorToEnd(bufferADT buffer)
{	
	cellT *temp = buffer->cursor->next;
	while(temp->next != NULL)
		temp = temp->next;
	buffer->ArrayCursor = temp->ArrayCount;
}
/*CHECK PREVIOUS PROGRAMS*/
void InsertCharacter(bufferADT buffer, char character)
{
	/*also be sure to create an if statement for the array cursor*/
	cellT *temp = buffer->cursor->next;
	int i = 0;
	/*if there isn't a first part*/
	if(buffer->cursor->next == NULL){
		cellT *cp;
		cp = New(cellT *);
		cp->ch[0] = character;
		cp->ArrayCount = 1;
		buffer->cursor->next = cp;
		buffer->ArrayCursor = 1;
	}
	/*Spliting fix this*/
	else if(temp->ArrayCount == 4){
		cellT *temp2;
		temp2 = New(cellT *);
		temp2->prev = temp;
		temp2->next = temp->next;
		if(temp->next != NULL)
			temp->next->prev = temp2;
		temp->next = temp2;
		temp2->ch[0] = temp->ch[2];
		temp2->ch[1] = temp->ch[3];
		temp->ch[2] = '\0';
		temp->ch[3] = '\0';
		temp->ArrayCount = 2;
		temp2->ArrayCount = 2;
		if(buffer->ArrayCursor == 2){
			buffer->cursor->next = temp2;
			buffer->ArrayCursor = 1;
			temp2->ch[buffer->ArrayCursor] = character;
			temp2->ArrayCount++;
			buffer->ArrayCursor++;
		}
		else if(buffer->ArrayCursor == 3){
			buffer->cursor->next = temp2;
			buffer->ArrayCursor = 2;
			temp2->ch[buffer->ArrayCursor] = character;
			temp2->ArrayCount++;
			buffer->ArrayCursor++;
		}
		else{
		temp->ch[buffer->ArrayCursor] = character;
		temp->ArrayCount++;
		buffer->ArrayCursor++;
		}
	}
	/*Moves the array to insert a character*/
	else if(buffer->ArrayCursor < temp->ArrayCount - 1){
		for(i = buffer->ArrayCursor; i < temp->ArrayCount; i++){
			char temp3 = temp->ch[i];
			temp->ch[i] = temp->ch[i+1];
			temp->ch[i+1] = temp3;
		}
		temp->ch[buffer->ArrayCursor] = character;
		temp->ArrayCount++;
	}
	/*not incrementing correctly*/
	else{
	temp->ch[buffer->ArrayCursor] = character;
	temp->ArrayCount++;
	buffer->ArrayCursor++;
	}
}
/*CHECK THE PAPER*/
void DeleteCharacter(bufferADT buffer)
{
	cellT *temp = buffer->cursor->next;
	if(temp->ArrayCount == 1 && temp->prev != NULL){
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
	else if(temp->ArrayCount == 1 && temp->prev == NULL && temp->next != NULL){
		buffer->cursor->next = temp->next;
		temp->next->prev = NULL;
		buffer->start->next = buffer->cursor;
		buffer->ArrayCursor = 0;
		free(temp);
	}
	else if(temp->ArrayCount - 1 == buffer->ArrayCursor){
		printf("There isn't anything else");
	}
	else{
		int i;
		for(i = buffer->ArrayCursor; i > temp->ArrayCount - 1; i++)
			temp->ch[i] = temp->ch[i+1];
		temp->ch[i+1] = '\0';
	}
}
void DisplayBuffer(bufferADT buffer)
{
	cellT *cp;
	int i = 0;
	for (cp = buffer->start->next; cp != NULL; cp = cp->next){
		printf("%s", cp->ch);
	}
	printf("\n");
	for (cp = buffer->start; cp != buffer->cursor; cp = cp->next){
		for(i = 0; i < cp->ArrayCount; i++)
			printf(" ");
	}
	for(i = 0; i < buffer->ArrayCursor; i++)
		printf(" ");
	printf("^\n");
}
