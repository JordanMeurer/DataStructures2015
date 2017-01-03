#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"
#define InitialStackSize 250
#define InitialBufferSize 250
#define true 1
#define false 0



struct stackCDT{
	stackElementT *elements;
	int count;
	int size;
};

static void ExpandStack(stackADT stack);
stackADT NewStack(void)
{
	stackADT stack;
	stack = (stackADT) malloc(sizeof *stack);
	stack->elements = malloc(InitialStackSize * sizeof(stackElementT));
	stack->count = 0;
	stack->size = InitialStackSize;
	return(stack);
}

void Push(stackADT stack, stackElementT element)
{
	if(stack->count == stack->size)
		ExpandStack(stack);
	stack->elements[stack->count++] = element;
}
stackElementT Pop(stackADT stack)
{
	if (StackIsEmpty(stack) == 1) 
		printf("Pop of an empty stack");
	return(stack->elements[--stack->count]);
}
int StackIsEmpty(stackADT stack)
{
	if(stack->count == 0)	
		return(1);
	else
		return(0);
}
bool StackIsFull(stackADT stack)
{
	return (false);
}
void FreeStack(stackADT stack)
{
	free(stack->elements);
	free(stack);
}
int StackDepth(stackADT stack)
{
	return (stack->count);
}
stackElementT GetStackElement(stackADT stack, int index)
{
	if(index < 0 || index >= stack->count)
		printf("Non-existent stack element");
return(stack->elements[stack->count - index - 1]);
}
static void ExpandStack(stackADT stack)
{
	stackElementT *array;
	int i, newSize;

	newSize = stack->size * 2;
	array = malloc(newSize * sizeof(stackElementT));
	for (i = 0; i < stack->count; i++)
		array[i] = stack->elements[i];
	free(stack->elements);
	stack->elements = array;
