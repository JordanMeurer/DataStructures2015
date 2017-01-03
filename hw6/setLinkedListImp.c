#include<stdio.h>
#include<stdlib.h>
#include "set.h"
#define MAXSIZE 100

typedef struct cellT{
	int x;
	struct cellT *next;
}cellT;

struct setCDT{
	cellT *start;
};

setADT setNew(void)
{
        setADT set;
        set = (setADT) malloc(sizeof(*set));
        set->start = NULL;
        return(set);
}
void setFree(setADT S)
{
        cellT *temp, *temp2;
        temp = S->start;
	temp2 = NULL;
	if(S->start->next == NULL)
		free(temp);
	else{
		temp2 = S->start->next;
	        while(temp->next != NULL){
			free(temp);
			temp = temp2;
	                temp2 = temp2->next;
	        }
		free(temp);
	}
        free(S);
}
int setInsertElementSorted(setADT S, setElementT E)
{
        cellT *temp, *temp2;
        temp = S->start;
        cellT *new;
	temp2 = NULL;
        new = (cellT*) malloc(sizeof(cellT));
	if(new == NULL){
		printf("Failed to create node");
		return 0;
	}
        new->x = E;
	new->next = NULL;
/*	if(E < temp->x){
		S->start = new;
		return;
	}
	while(temp != NULL && temp->x <= E){
		prev = temp;
		temp = temp->next;
	}
	new->next = temp;
	prev->next = new;
*/
	if(S->start == NULL){
		S->start = new;
		new->next = NULL;
		return;
	}
	temp2 = temp->next;
        while((temp->x < E) && (temp2 != NULL)){
                temp = temp2;
                temp2 = temp2->next;
	}
	if(new->x == temp->x){
		printf("You already inserted that, so I will skip it\n");
		free(new);
	}
	else if(new->x < S->start->x){
		new->next = S->start;
		S->start = new;
	}
        else{
        temp->next = new;
        new->next=temp2;
        }
}
setADT setUnion(setADT A, setADT B)
{
        setADT C;
	cellT *temp, *temp2, *temp3;
	cellT *prev = NULL;
	cellT *n = NULL;
	C = setNew();
	temp = A->start;
	temp2 = B->start;
	temp3 = NULL;
	int duplicate = 0;
	while(temp != NULL){
		duplicate = 0;
		temp2 = B->start;
		while(temp2 != NULL){
			if(temp->x == temp2->x)
				duplicate = 1;
			temp2 = temp2->next;
		}
		if(duplicate == 0){
			temp3 = (cellT*) malloc(sizeof(cellT));
			temp3->x = temp->x;
			temp3->next = NULL;
			if(C->start == NULL){
				C->start = temp3;
				prev = temp3;
				temp3 = temp3->next;
			}
			else{
			prev->next = temp3;
			prev = temp3;
			temp3 = temp3->next;
			}
		}
		temp = temp->next;
	}
	/*Errors starting here*/
	temp2 = B->start;
	cellT *i = C->start;
	cellT *j = NULL;
	while(temp2 != NULL){
		temp3 = (cellT*) malloc(sizeof(cellT));
		temp3->x = temp2->x;
		if(C->start == NULL)
			C->start = temp3;
		else{
			j = C->start->next;
			while((i->x < temp2->x) && (j != NULL)){
				i = j;
				j = j->next;
			}
			i->next = temp3;
		}
		temp3->next = j;
		temp3 = temp3->next;
		temp2 = temp2->next;
		i = C->start;
	}
	return(C);
}
/*	while(temp != NULL){
		temp3 = (cellT*) malloc(sizeof(cellT));
		temp3->x = temp->x;
		temp3->next = NULL;
		if(C->start == NULL){
			C->start = temp3;
			prev = temp3;
			temp = temp->next;
		}
		else{
			prev->next = temp3;
			temp = temp->next;
		}
	}
	while(temp2 != NULL){
		temp3 = (cellT*) malloc(sizeof(cellT));
		temp3->x = temp2->x;
		temp3->next = NULL;
		if(C->start == NULL)
			C->start = temp3;
		else if(temp3->x < C->start->x){
			temp3->next = C->start;
			C->start = temp3;
			temp2 = temp2->next;
		}
		else if(temp3->x == temp2->x)
			temp2 = temp2->next;
		else{
			temp2 = temp2->next;
		}
	}
}
	
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
}*/
/*Come back to this*/
setADT setDifference(setADT A, setADT B)
{
        setADT C;
	cellT *temp, *temp2;
	cellT *temp3 = NULL;
	cellT *prev = NULL;
	temp = A->start;
	temp2 = B->start;
	C = setNew();
	int difference = 1;
	while(temp != NULL){
		difference = 1;
		temp2 = B->start;
		while(temp2 != NULL){
			if(temp->x == temp2->x)
				difference = 0;
			temp2 = temp2->next;
		}
		if(difference == 1){
			temp3 = (cellT*) malloc(sizeof(cellT));
			temp3->x = temp->x;
			temp3->next = NULL;
			if(C->start == NULL){
				C->start = temp3;
				prev = temp3;
				temp3 = temp3->next;
			}
			else{
				prev->next = temp3;
				prev = temp3;
				temp3 = temp3->next;
			}
		}
		temp = temp->next;
	}
	/*never adds here*/
	temp2 = B->start;
	while(temp2 != NULL){
		difference = 1;
		temp = A->start;
		while(temp != NULL){
			if(temp2->x == temp->x)
				difference = 0;
			temp = temp->next;
		}
		if(difference == 1){
			temp3 = (cellT*) malloc(sizeof(cellT));
			temp3->x = temp2->x;
			temp3->next = NULL;
			if(C->start == NULL){
				C->start = temp3;
				prev = temp3;
				temp3 = temp3->next;
			}
			else{
				cellT *i = C->start;
				cellT *j = C->start->next;
				while((i->x < temp2->x) && (j != NULL)){
					i = j;
					j = j->next;
				}
				temp3->next = i->next;
				i->next = temp3;
			}	
		}
		temp2 = temp2->next;
	}
	return(C);
}
	
/*	while(temp != NULL){
		int unique = 1;
		while(temp2 != NULL){
			if(temp->x == temp2->x)
				unique = 0;
		temp2 = temp2->next;
		}
		if(unique == 1){
			temp3 = (cellT*) malloc(sizeof(cellT));
			temp3->x = temp->x;
			temp3->next = NULL;
		}
		temp = temp->next;
	}
}
	while(temp2 != NULL){
		difference = 1;
		while(temp != NULL){
			if(temp->x == temp2->x)
				difference = 0;
			temp = temp->next;
			}
		if(difference == 1){
			C->num = A->num;
			C = C->next;
		temp2 = temp->next;

        return(C);
}*/
setADT setIntersection(setADT A, setADT B)
{
        setADT C; 
	cellT *temp, *temp2, *temp3, *prev;
	temp = A->start;
	temp2 = B->start;
	temp3 = NULL;
	prev = NULL;
	C = setNew();
	int intersection = 0;
	while(temp != NULL){
		intersection = 0;
		temp2 = B->start;
		while(temp2 != NULL){
			if(temp->x == temp2->x)
				intersection = 1;
			temp2 = temp2->next;
		}
		if (intersection == 1){
			temp3 = (cellT*) malloc(sizeof(cellT));
			temp3->x = temp->x;
			temp3->next = NULL;
			if(C->start == NULL){
				C->start = temp3;
				prev = temp3;
				temp3 = temp3->next;
			}
			else{
				prev->next = temp3;
				prev = temp3;
				temp3 = temp3->next;
			}
		}
		temp = temp->next;
	}
	return(C);
}
/*	while(temp !=NULL){
		while(temp2 != NULL){
			if(temp->x = temp2->x){
				temp3 = (cellT*) malloc(sizeof(cellT));
				temp3->x = temp->x;
				temp3->next = NULL;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
	while(temp != NULL){
		while(temp2 != NULL){
			if(temp->x = temp2->x){
				C->num = temp->num;
				C = C->next;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
        return(C);
}*/
/*returns the number of elements in a set*/
int setCardinality(setADT S)
{
        int length = 0;
	cellT *temp = S->start;
        while(temp->next != NULL){
                temp = temp->next;
                length++;
        }
        return(length);
}
/*prints the elements of the set*/
void setPrint(setADT S, char name)
{
	cellT *temp;
	temp = S->start;
        printf("The set %c is {", name);
        while(temp != NULL){
		int i = temp->x;
                printf(" %d,", i);
		temp = temp->next;
	}
	printf("}\n");
}
