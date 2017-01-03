#include<stdio.h>
#include<stdlib.h>
#include "set.h"
#define MAXSIZE 100

struct setCDT{
	int array[MAXSIZE];
	int length;
};

/*Only one set since the driver program will call this twice to create 2 sets (A & B)*/
setADT setNew(void)
{
	setADT set;
	set = malloc(sizeof *set);
	set->length = 0;
	return(set);
}
/* Call this to free the set structure*/
void setFree(setADT S)
{
	free(S);
}
/* This will input the numbers into a set and orginize, will return the number of elements*/
int setInsertElementSorted(setADT S, setElementT E)
{
	int i, temp;
	S->array[S->length] = E;
	S->length++;
	if(S->length > 1){
		for(i = S->length-1; i > 0; i--){
			if(S->array[i] < S->array[i-1]){
				temp = S->array[i];
				S->array[i] = S->array[i-1];
				S->array[i-1] = temp;
			}
		}
	}
	if(S->array[S->length] == '\0')
		return 0;
}
/*this will return the Union of set A and B*/
setADT setUnion(setADT A, setADT B)
{
	int i, j, duplicate, k, l, temp, m;
	setADT Union;
	Union = malloc(sizeof *Union);
	Union->length = 0;
	for(i=0; i < A->length; i++){
	duplicate = 0;
		for(j=0; j< B->length; j++){
			if(A->array[i] == B->array[j])
				duplicate = 1;
		}
		if(duplicate == 0){
			Union->array[Union->length] = A->array[i];
			Union->length++;
		}
	}
	for(m = 0; m < B->length; m++){
		Union->array[Union->length] = B->array[m];
		Union->length++;
	}
	for(k = 0; k < Union->length; k++){
		for(l = 0; l < Union ->length - 1; l++){
			if(Union->array[l] > Union->array[l+1]){
				temp = Union->array[l];
				Union->array[l] = Union->array[l+1];
				Union->array[l+1] = temp;
			}
		}
	}
	return(Union);
}
/*this will return the Intersection of set A and B*/
setADT setIntersection(setADT A, setADT B)
{
	setADT Intersection;
	Intersection = malloc(sizeof *Intersection);
	Intersection->length = 0;
	int i, j;
	for(i=0; i < A->length; i++){
		for(j = 0; j < B->length; j++){
			if(A->array[i] == B->array[j]){
				Intersection->array[Intersection->length] = A->array[i];
				Intersection->length++;
			}
		}
	}
	return(Intersection);
}
/* see if you have to check for doubles within the same set*/
/*this will return the Difference of set A and B*/
setADT setDifference(setADT A, setADT B)
{
	setADT Difference;
	Difference = malloc(sizeof *Difference);
	Difference->length = 0;
	int i, j, unique, k, l, m, n, temp;
	for(i=0; i < A->length; i++){
		unique = 1;
		for(j = 0; j < B->length; j++){
			if(A->array[i] == B->array[j])
				unique = 0;
		}
		if(unique == 1){
			Difference->array[Difference->length] = A->array[i];
			Difference->length++;
		}
	}
	return(Difference);
}
/*returns the number of elements in a set*/
int setCardinality(setADT S)
{
	return(S->length);
}
/*prints the elements of the set*/
void setPrint(setADT S, char name)
{
	int i, temp;
		printf("The %c is: {", name);
		for(i = 0; i < S->length; i++){
			temp = S->array[i];
			printf(" %d,", temp);
	}
	printf("}\n");
}
