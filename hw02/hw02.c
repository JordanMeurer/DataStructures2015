#include<stdio.h>
#include<stdlib.h>

#define ROW 11 
#define COL 12

void SearchGrid(char grid[ROW][COL],char *argv[],int argc);

int main(int argc, char *argv[])
{
	if(argc == 1){
		printf("Please at least enter an arguement.\n");
		exit(0);
	}
	/*The grid of letters*/
	char g[ROW][COL] ={	{'c', 'a', 'a', 'l', 'a', 'b', 'd', 'u', 'c', 'k', 'e'},
				{'h', 'a', 'f', 'i', 's', 'h', 'e', 'a', 'a', 'a', 'l'},
				{'i', 'a', 'd', 'o', 'g', 'a', 'e', 'a', 'a', 'h', 'e'},
				{'c', 'a', 'a', 'n', 'a', 'a', 'r', 'a', 'r', 'o', 'p'},
				{'k', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'r', 'h'},
				{'e', 'a', 'a', 'a', 'c', 'a', 't', 'a', 'a', 's', 'a'},
				{'n', 'f', 'r', 'o', 'g', 'o', 'a', 't', 'a', 'a', 'n'},
				{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 't'},
				{'a', 'a', 'a', 'd', 'o', 'l', 'p', 'h', 'i', 'n', 'a'},
				{'h', 'o', 'r', 's', 'e', 'a', 'a', 'a', 'a', 'a', 'a'}};
				/* Animals, so lion[0][3] downward, cat[5][4] across, dog[2][2] diagnal, bear[0][5], chicken[0][0] downward*/
				/* deer[0][6] downward, dolphin[8][3] across, duck[0][6] across, elephant[0][9] downard, fish[1][2], frog[6][1] across*/
				/*goat[6][4] across, horse[9][0] across*/
	SearchGrid(g, argv, argc);
	return 0;
}
/* Searches the grid to find the words within the grid, prints out if it finds it within the grid or not. */
void SearchGrid(char grid[ROW][COL],char *argv[],int argc)
{
	int i, j, k, row1, col1, a;
	for(k = 1; k <= argc-1; k++){
		int test = 0;
		row1 = 0, col1 = 0;
		for(i = 0; i < ROW; i++){
			for(j = 0; j < COL; j++){
				/* first letter check */
				if(argv[k][0] == grid[i][j]){
					row1 = i;
					col1 = j;
					/*horizontal*/
					if(argv[k][1] == grid[i][j+1]){
						int j1 = j+1;
						int a1 = 1;
						while(argv[k][a1] == grid[i][j1] && argv[k][a1] != '\0' && j1 < COL){
							a1++;
							j1++;
						}
						if(argv[k][a1] == '\0'){
							printf("We found %s at (%d,%d) of the grid going horizontal\n", argv[k], row1, col1);
							test = 1;
						}
					}
					/*vertical*/
					if(argv[k][1] == grid[i+1][j]){
						int i1 = i+1;
						int a2 = 1;
						while(argv[k][a2] == grid[i1][j] && argv[k][a2] != '\0' && i1 < ROW){
							a2++;
							i1++;
						}
						if(argv[k][a2] == '\0'){
							printf("We found %s at (%d,%d) of the grid going vertical\n", argv[k], row1, col1);
							test = 1;
						}
					}
					/*diagnal*/
					if(argv[k][1] == grid[i+1][j+1]){
						int i2 = i+1;
						int j2 = j+1;
						int a3 = 1;
						while(argv[k][a3] == grid[i2][j2] && argv [k][a3] != '\0' && j2 < COL && i2 < ROW){
							a3++;
							i2++;
							j2++;
						}
						if(argv[k][a3] == '\0'){
							printf("We found %s at (%d,%d) of the grid going diagnal\n", argv[k], row1, col1);
							test = 1;
						}
					}
				}
			}
		}
		if(test == 0)
			printf("%s was not found inside the grid\n", argv[k]);
	}
}	
