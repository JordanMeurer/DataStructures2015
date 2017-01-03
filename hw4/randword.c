#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "randword.h"

void InitDictionary(char* dictionary)
{
        int i = 0; 
        FILE* fp = fopen(dictionary, "r"); 
        while(fscanf(fp, "%s", Words[i++]) == 1)
                WordCount++;
	fclose(fp);
}
int ChooseRandomWord()
{
        srand(time(NULL));
        int select = (rand() % (WordCount));
        /* So that means that i is the number of rows*/
        return select;
}
