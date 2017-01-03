#ifndef _stack_h
#define _stack_h

#define New(ptr_t) ((ptr_t)malloc(sizeof*((ptr_t)NULL)))
typedef int bool;

typedef double stackElementT;

typedef struct stackCDT *stackADT;

stackADT NewStack(void);
void FreeStack(stackADT stack);
void Push(stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackIsEmpty(stackADT stack);
bool StackIsFull(stackADT stack);
int StackDepth(stackADT stack);
stackElementT GetStackElement(stackADT stack, int index);
//char* GetLine(FILE* infile);

#endif
