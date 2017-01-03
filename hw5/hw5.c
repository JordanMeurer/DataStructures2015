#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"

int main(int argc, char* argv[]){
	/*main file*/
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("There isn't a file!\n");
		exit(0);
	}
	stackADT stack1;
	char line[256];
	char ch;
	int i = 0, header = 1;
	stack1 = NewStack();
	printf(">");
	while(fgets(line, 256, fp) != NULL){
	for(i = 0;i < strlen(line); i++){
              	if(line[i] == '<' && line[i+1] == 'i')
			Push(stack1, line[i+1]);
                if(line[i] == '<' && line[i+1] == 'a')
                        Push(stack1, line[i+1]);
                if(line[i] == '<' && line[i+1] == 'u')
                        Push(stack1, line[i+1]);
                if(line[i] == '<' && line[i+1] == 'l')
                        Push(stack1, line[i+1]);
                if(line[i] == '<' && line[i+1] == 'd')
                        Push(stack1, line[i+1]);
                if(line[i] == '<' && line[i+1] == 't')
                        Push(stack1, line[i+1]);
                if(line[i] == '<' && line[i+1] == 'p')
                        Push(stack1, line[i+1]);
		if(line[i] == '<' && line[i+1] == 'b' && line[i+2] != 'o' && line[i+2] != 'r')
			Push(stack1, line[i+1]);
		if(line[i] == '<' && line[i+1] == 'b' && line[i+2] == 'o') /*body*/
			Push(stack1, line[i+2]);
		if(line[i] == '<' && line[i+1] == 's' && line[i+2] == 't' && line[i+3] == 'y') /*style*/
			Push(stack1, line[i+3]);
		if(line[i] == '<' && line[i+1] == 's' && line[i+2] == 'c') /*script*/
			Push(stack1, line[i+2]);
		if(line[i] == '<' && line[i+1] == 's' && line[i+2] == 'p' && line[i+3] == 'a' && line[i+4] == 'n') /*span*/
			Push(stack1, line[i+4]);
//		if(line[i] == '<' && line[i+1] == 'h' && line[i+2] == 't' && line[i+3] == 'm' && line[i+4] == 'l') /*html*/
//			Push(stack1, 'l');
		if(line[i] == '<' && line[i+1] == 'h' && line[i+2] == 't')  /*TEST*/
			Push(stack1, line[i+1]);
		if(line[i] == '<' && line[i+1] == 'h' && line[i+2] != 't') /*header*/
			Push(stack1, 'e');
		//check the Pop
		if(line[i] == '<' && line[i+1] == '/'){
			if(line[i+2] == 'i' && Pop(stack1) != 'i') break;
			if(line[i+2] == 'a' && Pop(stack1) != 'a') break;
			if(line[i+2] == 'u' && Pop(stack1) != 'u') break;
			if(line[i+2] == 'l' && Pop(stack1) != 'l') break;
			if(line[i+2] == 'd' && Pop(stack1) != 'd') break;
			if(line[i+2] == 't' && Pop(stack1) != 't') break;
                        if(line[i+2] == 'p' && Pop(stack1) != 'p') break;
			if(line[i+2] == 'h' && line[i+3] == 't' && Pop(stack1)  != 'q') break;  /*TEST*/
			if(line[i+2] == 'h' && Pop(stack1) != 'e' && line[i+3] != 't') break;
//			if(line[i+2] == 'h' && line[i+3] == 't' && Pop(stack1) != 'm') break;
			if(line[i+2] == 'b' && line[i+3] != 'o' && Pop(stack1) != 'b') break;
			if(line[i+2] == 'b' && line[i+3] == 'o' && Pop(stack1) != 'o') break;
			if(line[i+2] == 's' && line[i+3] == 't' && Pop(stack1) != 'y') break;
			if(line[i+2] == 's' && line[i+3] == 'c' && Pop(stack1) != 'c') break;
			if(line[i+2] == 's' && line[i+3] == 'p' && Pop(stack1) != 'n') break;
		}
		printf("%c", line[i]);
	}
	}
	printf("\n");
	if(StackIsEmpty(stack1) == 1)
		printf("Brackets are propertly nestesd\n");
	else
		printf("Brackets are not properly nested");
	FreeStack(stack1);
	fclose(fp);
	return 0;
}
