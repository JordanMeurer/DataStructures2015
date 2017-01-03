#include<stdio.h>
#include<stdlib.h>
#include "set.h"
#define MAX 100
int main()
{
	int go = 1, number = 0;			/*int for the while loop*/
	char answer;
	setADT A = setNew();			/*creates setA*/
	setADT B = setNew();			/*Creates setB*/
	printf("Insert numbers for setA and I will stop when you put -1\n");
	while(go == 1){
		scanf("%d",&number);
		if(number == -1)
			break;
		setInsertElementSorted(A, number);
	}
	printf("Insert numbers for setB and I will stop when you put -1\n");
	while(go == 1){
		scanf("%d%*c", &number);
		if(number == -1)
			break;
		setInsertElementSorted(B, number);
//	scanf("%*c");
	}
	/*setInsertElementSorted x2, ask the user for input for A and B*/
	while(go == 1){
		printf("Please enter a command: 'U' for Union, 'I' for Intersection, 'D' for difference or 'Q' to quit.\n");
		scanf("%c%*c", &answer);
		if(answer == 'U' || answer == 'u'){
			setADT C = setUnion(A, B);
			setPrint(A, 'A');
			setPrint(B, 'B');
			setPrint(C, 'C');
			setFree(C);
		}
		else if(answer == 'I' || answer == 'i'){
			setADT C = setIntersection(A, B);
                        setPrint(A, 'A');
                        setPrint(B, 'B');
                        setPrint(C, 'C');
			setFree(C);
		}
		else if(answer == 'D' || answer == 'd'){
			setADT C = setDifference(A, B);
                        setPrint(A, 'A');
                        setPrint(B, 'B');
                        setPrint(C, 'C');
			setFree(C);
		}
		else if(answer == 'Q' || answer == 'q'){
			printf("Okay closing the program!\n");
			break;
		}
		else{
			printf("That was not a choice, please enter a choice again.\n");
		}
	}
	setFree(A);				/*frees setA*/
	setFree(B);				/*frees setB*/
	return 0;
}
