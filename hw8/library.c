#include<stdio.h>
#include<stdlib.h>
#include "library.h"

typedef struct nodeT{
	int x;
	struct nodeT* left;
	struct nodeT* right;
};
/*printing options*/
void PrintOptions()
{
	printf("I: insert\n");
	printf("F: find\n");
	printf("D: delete\n");
	printf("O: list in order\n");
	printf("E: list in pre order\n");
	printf("P: list in post order\n");
	printf("L: level order\n");
	printf("A: max\n");
	printf("M: min\n");
	printf("H: height\n");
	printf("C: count\n");
	printf("S: sum\n");
	printf("Q: quit\n");
	Choice();
}

void Choice(char answer)
{

	if(answer == 'i' || answer == 'I'){
		int i;
		printf("Please insert a positive integer to insert");
		scanf("%d", i);
		insert(t, i);		
	else if(answer == 'f' || answer == 'F'){
		int j;
		printf("Please enter a positive integer to search for");
		scanf("%d", j);
		find(t, i);
	else if(answer == 'd' || answer ==  'D')
		int k;
		printf("Please enter a positive integer to delete");
		scanf("%d", k);
		delete(nodeT *t);
	else if(answer == 'o' || answer == 'O')
		list_in_order(nodeT *t);
	else if(answer == 'e' || answer == 'E')
		list_pre_order(nodeT *t);
	else if(answer == 'p' || answer == 'P')
		list_post_order(nodeT *t);
	else if(answer == 'l' || answer == 'L')
		list level_order(nodeT *t);
        else if(answer == 'a' || answer == 'A')
		max(nodeT *t);
        else if(answer == 'm' || answer == 'M')
		min(nodeT *t);
        else if(answer == 'h' || answer == 'H')
		height(nodeT *t);
        else if(answer == 'c' || answer == 'C')
		count(nodeT *t);
        else if(answer == 's' || answer == 'S')
		sum(nodeT *t);
	else if(answer == 'q' || answer == 'Q')
		quit(nodeT *t);
	else{
		printf("Invalid option, here is a list of options");
		PrintOptions();
	}
}
struct nodeT* newNode()
{
	nodeT* t = (nodeT*) malloc(sizeof(nodeT));
	t->left = NULL;
	t->right =NULL;
	return (t);
}
/*Finish this later*/
int insert(nodeT *t, int i)
{
	if(t == NULL){
		nodeT *t = newNode();
		t->x = i;
	}
	else{
		if(i <= t->x)
			t->left = insert(t->left, i);
		else
			t->right = insert(t->right, i);
	}
	return t;	
}
/*finish this later, recursion? (return left and right and check if they match, then return if tehy do, return 0 if nothing*/
int find(nodeT *t, int i)
{
	if(t == NULL)
		return 0;
}
/*finish this later*/
int delete(nodeT *t)
{
	if(t == NULL)
		return 0;
}

int list_in_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	inorder(t->left);
	printf("%d", t->x);
	inorder(t->right);
}

int list_pre_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	printf("%d", t->x);
	list_pre_order(t->left);
	list_pre_order(t->right);
}

int list_post_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	list_post_order(t->left);
	list_post_order(t->right);
	printf("%d", t->x);
}
/* come back to this later, you will have to call height*/
int level_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	if

}

int max(nodeT *t)
{
	if(t == NULL)
		return 0;
	int left = max(t->left);
	int right = max(t->right);
	
	return max(
}

int min()
{
	if(t == NULL)
		return 0;
}

int height(nodeT *t)
{
	if(t == NULL)
		return 0;
	else{
		int lheight = height(t->left);
		int rhight = height(t->right);
	
		if(lheight > rhight)
			return(lheight+1)
		else
			return(rheight+1);
	}
}

}
/* be sure to change a few things within the function, mainly node*/
int count(nodeT *t)
{
	if(t == NULL)
		return 0;
	if(t->left == NULL && t->right == NULL)
		return 1;
	else
		return count(t->left) + count(t->right);
}
/* seems right*/
int sum(nodeT *t)
{
	if(t == NULL)
		return 0;
	return t->x + sum(t->left) + sum(t->right);
}
/*free each part with a order (post order?)*/
void quit(nodeT *t)
{
	if(t != 0){
		quit(t->left);
		quit(t->right);
		free(t);
	}
}
