#include<stdio.h>
#include<stdlib.h>
/*defining the structure*/
typedef struct nodeT{
	int x;
	struct nodeT* left;
	struct nodeT* right;
}nodeT;
/*prototyes*/
struct nodeT* newNode();
void PrintOptions();
int Choice(nodeT *t); 
void insert(nodeT **t, int i);
struct nodeT* find(nodeT* t, int i);
void printlevel(nodeT* t, int i);
int delete(nodeT **root, int i);
int list_in_order(nodeT* t);
int list_pre_order(nodeT* t);
int list_post_order(nodeT* t);
int list_level_order(nodeT* t);
int max(nodeT* t);
int min(nodeT* t);
int height(nodeT* t);
int count(nodeT* t);
int sum(nodeT* t);
void quit(nodeT* t);
int main()
{
	int h = 1;
	nodeT *t = NULL;
	printf("Welcome to the tree function, here are your options:\n");
	PrintOptions();
	while(h == 1){
		if(Choice(t) == 0)
			break;
	}
	return 0;
}
/*prints the options the first time and everytime an invalid input is used*/
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
}
/*gets the input from the user and runs the function based on the user input*/
int Choice(nodeT *t)
{
	int i, j, k;
	char answer;
	printf("*");
	scanf(" %c", &answer);
	if(answer == 'i' || answer == 'I'){
		scanf(" %d", &i);
		insert(&t, i);
		Choice(t);
	}
	else if(answer == 'f' || answer == 'F'){
		scanf(" %d", &j);
		if(find(t, j) != 0)
			printf("We found %d in the tree!\n", j);
		else
			printf("%d is not in the tree.\n", j);
                printf("Okay next command\n");
                Choice(t);
	}
	else if(answer == 'd' || answer ==  'D'){
		int i = 0;
		scanf(" %d", &k);
		delete(&t, k);
                printf("Okay next command\n");
                Choice(t);
	}
	else if(answer == 'o' || answer == 'O'){
		list_in_order(t);
		printf("\n");
                Choice(t);
	}
	else if(answer == 'e' || answer == 'E'){
		list_pre_order(t);
		printf("\n");
                Choice(t);
	}
	else if(answer == 'p' || answer == 'P'){
		list_post_order(t);
		printf("\n");
                Choice(t);
	}
	else if(answer == 'l' || answer == 'L'){
		list_level_order(t);
		Choice(t);
	}
        else if(answer == 'a' || answer == 'A'){
		int maximum = max(t);
		printf("The max is: %d\n", maximum);
		Choice(t);
	}
        else if(answer == 'm' || answer == 'M'){
		int minimum = min(t);
		printf("The minimum is: %d\n", minimum);
		Choice(t);
	}
        else if(answer == 'h' || answer == 'H'){
		int size = height(t);
		printf("The height is: %d\n", size);
		Choice(t);
	}
        else if(answer == 'c' || answer == 'C'){
		int amount = count(t);
		if(amount == 0)
			printf("There isn't a binary tree!");
		else
			printf("The count is: %d\n", amount);
		Choice(t);
	}
        else if(answer == 's' || answer == 'S'){
		int total = sum(t);
		printf("The sum is : %d\n", total);
		Choice(t);
	}
	else if(answer == 'q' || answer == 'Q'){
		quit(t);
		printf("Program is closing\n");
		return 0;
	}
	else{
		printf("Invalid option, here is a list of options\n");
		PrintOptions();
		Choice(t);
	}
	return 0;
}
/*creates a new node for the binary tree*/
struct nodeT* newNode()
{
	nodeT* t =(nodeT*) malloc(sizeof(nodeT));
	t->left = NULL;
	t->right =NULL;
	t->x = 0;
	return (t);
}
/*finds where to insert the node and inserts it*/
void insert(nodeT **t, int i)
{
	nodeT *temp;
	temp = *t;
	if(temp == NULL){
		temp = newNode();
		temp->x = i;
		*t = temp;
	}
	else{
		if(i < temp->x)
			insert(&temp->left, i);
		else if(i == temp->x){
			printf("This value was already inserted, so I'm not going to add it again\n");
			return;
		}
		else
			insert(&temp->right, i);
	}	
}
struct nodeT* find(nodeT *t, int i)
{
	if(t == NULL)
		return 0;
	if(i == t->x)
		return t;
	else if(i < t->x)
		return find(t->left, i);
	else
		return find(t->right, i);
}
/*finish this later, if it returns 0, be sure to say if it was able to delete it or not*/
int delete(nodeT **root, int r)
{
	nodeT *target, *lmd_r, *plmd_r;
	target = *root;
	if(target->left == NULL && target->right == NULL)
		*root = NULL;
	else if(target->left == NULL)
		*root = target->right;
	else if(target->right == NULL)
		*root = target->left;
	else{
		plmd_r = target;
		lmd_r = target->right;
		while(lmd_r->left != NULL){
			plmd_r = lmd_r;
			lmd_r = lmd_r->left;
		}
		if(plmd_r == target)
			plmd_r->right = lmd_r->right;
		else
			plmd_r->left = lmd_r->right;
		lmd_r->left = target->left;
		lmd_r->right = target->right;
		*root = lmd_r;
	}
	free(target);
	return 1;
}
int list_in_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	list_in_order(t->left);
	printf("%d ", t->x);
	list_in_order(t->right);
	return 1;
}

int list_pre_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	printf("%d ", t->x);
	list_pre_order(t->left);
	list_pre_order(t->right);
	return 1;
}

int list_post_order(nodeT *t)
{
	if(t == NULL)
		return 0;
	list_post_order(t->left);
	list_post_order(t->right);
	printf("%d ", t->x);
	return 1;
}
/*prints each level of the nodes*/
int list_level_order(nodeT *t)
{
	int i;
	if(t == NULL)
		return 0;
	int a = height(t);
	for(i = 1; i <= a; i++){
		printlevel(t, i);
		printf("\n");
	}
	return 1;
}
void printlevel(nodeT *t, int i)
{
	if(t == NULL)
		return;
	if(i == 1)
		printf("%d ", t->x);
	else if(i > 1){
		printlevel(t->left, i - 1);
		printlevel(t->right, i - 1);
	}
}
int max(nodeT *t)
{
	int i = t->x;
	if(t == NULL)
		return 0;
	else if(t->right == NULL)
		return i;
	else
		return(max(t->right));
}

int min(nodeT *t)
{
	int i = t->x;
        if(t == NULL)
                return 0;
	else if(t->left == NULL)
		return i;
	else
		return(min(t->left));
}

int height(nodeT *t)
{
	int lheight = 0, rheight = 0;
	if(t == NULL)
		return 0;
	else{
		if(t->left != NULL)
			lheight = height(t->left);
		if(t->right != NULL)
			rheight = height(t->right);
	
		if(lheight > rheight)
			return(lheight+1);
		else
			return(rheight+1);
	}
}
/*counts the total number of nodes*/
int count(nodeT *t)
{
	int NodeCount = 0;
	if(t == NULL)
		return 0;
	else
		NodeCount = 1 + count(t->left)+count(t->right);
	return NodeCount;
}
int sum(nodeT *t)
{
	if(t == NULL)
		return 0;
	return t->x + sum(t->left) + sum(t->right);
}
/*frees the binary tree before quitting*/
void quit(nodeT *t)
{
	if(t == NULL)
		return;
	else if(t != NULL){
		quit(t->left);
		quit(t->right);
		free(t);
	}
}
