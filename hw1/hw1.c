#include<stdio.h>
#include<stdlib.h>

int choicefnc();
void puzzle();
void solution();
void doesitwork(int check[][9]);
void SudokuCheck(int a[][9],int mode);
void PossibleValue(int row, int column,int Sudoku[][9]);

int main(int argv, char *argc[])
{
	choicefnc();
	return 0;
}
/*Checks what mode the user wants to use*/
int choicefnc()
{
	int choice = 0;
	printf("Please have a 1 for puzzle or 2 for solution at the top of the file followed by 81 numbers with 0s for blanks (default is 1 if no valid input): \n");
	scanf("%d", &choice);
		if(choice == 1)
			puzzle();
		else if(choice == 2)
			solution();
		else
			printf("Not a valid option, so we are going with 1: Puzzle\n");
}
/* if the user choose to do the puzzle, it will run this function*/
void puzzle()
{
	int i, j, x, count = 0;
	int SudokuPuzzle[9][9] = {0};
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			scanf("%d", &x);
			count++;
			if(x > 9 || x < 0){
				printf("WHOA, we have a problem here, a number was out of bounds for the Sudoku range!\n");
				exit(2);
			}
			SudokuPuzzle[i][j] = x;
		}
	}
	doesitwork(SudokuPuzzle);
	SudokuCheck(SudokuPuzzle, 1);
}
/* if the user chooses to the do the solution, it will run this function*/
void solution()
{
        int i, j, x, count = 0;
        int SudokuSolution[9][9] = {0};
        for(i = 0; i < 9; i++)
        {
                for(j = 0; j < 9; j++)
                {
			count++;
                        scanf("%d", &x);
			if(x > 9 || x < 1){
				printf("WHOA, we have a problem here, a number was out of bounds for the Sudoku range! (1-9)\n");
				exit(3);
			}
                        SudokuSolution[i][j] = x;
                }
        }
	doesitwork(SudokuSolution);
	SudokuCheck(SudokuSolution, 2);
}
/* checks both the problem and solution of the sudoku puzzle*/
void SudokuCheck(int a[][9], int mode)
{
	/*test 2 means false, there is a problem, test 1 means it passes without an issue*/
	int test = 1, i, j, k, l = 0;
	/*horizontal check*/
	for(k = 0; k < 9; k++){
		for(i = 0; i < 8; i++){
			for(j = i+1; j < 9; j++){
				if(a[k][i] == a[k][j] && a[k][i] != 0){
					test = 2;
					l++;
					printf("%d. There is a problem at (%d,%d) & (%d,%d) where they are the same value\n",l, k+1,i+1, k+1, j+1);
				}
			}
		}
	}
	/*vertical check*/
	for(k = 0; k < 9; k++){
		for(i = 0; i < 8; i++){
			for(j = i+1; j < 9; j++){
				if(a[i][k] == a[j][k] && a[i][k] != 0){
				test = 2;
				l++;
				printf("%d. There is a problem at (%d,%d) & (%d,%d) where they are the same value\n",l, i+1, k+1, j+1, k+1);
				}
			}
		}
	}
        if(test == 1 && mode == 2){
        for(i = 1; i < 8; i += 3){
                for(j = 1; j < 8; j += 3){
                        if(a[i-1][j-1] + a[i-1][j] + a[i-1][j+1]+ a[i][j-1] + a[i][j]+a[i][j+1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1] != 45){
                                printf("Hey there was an problem at the (%d,%d) box, there must be a value that appears 2 or more times within this box!\n", i, j);
                                test = 2;
                                }
                        }
                }
        }
	if(test == 1 && mode == 2)
		printf("Good job, the solution follows the Sudoku rules!\n");
	if(test == 2 && mode == 2)
		printf("The solution does NOT follow the Sudoku rules, check the log above to see where the issues were.\n");
	if(test == 1 && mode == 1){
		printf("It seems that the puzzle should work from here, I will print out possible solutions for each empty slot\n");
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(a[i][j] == 0)
					PossibleValue(i, j, a);
			}
		}
	}
	if(test == 2 && mode == 1)
		printf("The puzzle does NOT follow the Sudoku rules, check the log above to see where the issue(s) were.\n");
}
/* prints out the puzzle/solution to show the user their input file*/		
void doesitwork(int check[][9])
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		printf("\n");
		for(j = 0; j < 9; j++)
		{
			printf("%2d", check[i][j]);
		}
	}
	printf("\n");
}
/*checks the possible values and prints them out for the user*/
void PossibleValue(int row, int column, int Sudoku[][9])
{
	int possible[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int count = 0, i, j, k, r, c;
	/*horizontal*/
	for(i = 0; i <= 8; i++){
		if(Sudoku[row][i] != 0)
			possible[Sudoku[row][i]] = 0;
	}
	/*vertical*/
	for(j = 0; j <= 8; j++){
		if(Sudoku[j][column] != 0)
			possible[Sudoku[j][column]] = 0;
	}
	/*grid check*/
	for(r = (row / 3) * 3; r < (row / 3) * 3 + 3; r++){
		for(c = (column / 3) * 3; c < (column / 3) * 3 + 3; c++){
			if(Sudoku[r][c] != 0)
				possible[Sudoku[r][c]] = 0;
		}
	}
	printf("These are the possible values for (%d, %d):", row + 1, column + 1);
	for(k = 0; k < 10; k++){
		if(possible[k] != 0)
			printf("%d ", possible[k]);
	}
	printf("\n");
}
