#include<stdio.h>
#include<stdlib.h>
#include "set.h"
#define MAXSIZE 100

typedef struct cell{
	int x;
	struct cell *next;
}cellT;

struct setCDT{
	cellT *start;
	int num;
};

setADT setNew(void)
{
        setADT set;
        set = (setADT) malloc(sizeof(*set));
        set->start = NULL;
	set->num = 0;
        return(set);
}
void setFree(setADT S)
{
        setADT temp, temp2;
        temp = S;
        temp2 = S->next;
        while(temp->next != NULL){
                free(temp);
                temp = temp2;
                temp2 = temp2->next;
        }
        free(temp);
}
int setInsertElementSorted(setADT S, setElementT E)
{
        setADT temp, temp2;
        temp = S;
        temp2 = S->next;
        setADT new;
        new = (setADT) malloc(sizeof(new));
        new->num = E;
        while(!(temp->num > E) && !(temp2->num < E) && (temp2!= NULL)){
                temp = temp2;
                temp2 = temp2->next;
        }
        if(temp2 = NULL)
                temp->next = new;
        else{
        temp->next = new;
        new->next=temp2;
        }
}
setADT setUnion(setADT A, setADT B)
{
        setADT C, temp, temp2;
	C = (setADT) malloc(sizeof(C));
	temp = A;
	temp2 = B;
	while(temp != NULL){
		C->num = temp->num;
		C = C->next;
		temp = temp->next;
	}
	while(temp2 != NULL){
		C->num = temp2->num;
		C = C->next;
		temp2 = temp2->next;
	}
	/*Can't figure out how to orginize this, but whatever, I can't even get the program to work :)*/
        return(C);
}
setADT setDifference(setADT A, setADT B)
{
        setADT C, temp, temp2;
	int difference;
	temp = A;
	temp2 = B;
	C = (setADT) malloc(sizeof(C));
	while(temp2 != NULL){
		difference = 1;
		while(temp != NULL){
			if(temp->num == temp2->num)
				difference = 0;
			temp = temp->next;
			}
		if(difference == 1){
			C->num = A->num;
			C = C->next;
		temp2 = temp->next;

        return(C);
}
setADT setIntersection(setADT A, setADT B)
{
        setADT C, temp, temp2;
	temp = A;
	temp2 = B;
	C = (setADT) malloc(sizeof(C));
	while(temp != NULL){
		while(temp2 != NULL){
			if(temp->num = temp2->num){
				C->num = temp->num;
				C = C->next;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
        return(C);
}
/*returns the number of elements in a set*/
int setCardinality(setADT S)
{
        int length = 0;
        while(S->next != NULL){
                S = S->next;
                length++;
        }
        return(length);
}
/*prints the elements of the set*/
void setPrint(setADT S, char *name)
{
        printf("The set %c is { ", name);
        while(S->next != NULL){
                int i = S->num;
                printf(" %d", i);
                S = S->next;
}
