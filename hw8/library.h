#ifndef library h
#define library h

typedef struct nodeT;


struct nodeT* newNode(int i);
void PrintOptions();
int Choice(char answer); 
int insert(nodeT* t);
int find(nodeT* t);
int delete(nodeT* t);
int list_in_order(nodeT* t);
int list_pre_order(nodeT* t);
int list post_order(nodeT* t);
int level_order(nodeT* t);
int max(nodeT* t);
int min(nodeT* t);
int height(nodeT* t);
int count(nodeT* t);
int sum(nodeT* t);
void quit(nodeT* t);

#endif


