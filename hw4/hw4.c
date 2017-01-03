//#include "randword.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

//char* InitDictionary(char* dictionary);
//char* ChooseRandomWord(char* Words);


int main(int argc, char* argv[]){
	extern int WordCount;										//imported from the library file
	extern char Words[40][40];									//imported from the library file
	InitDictionary(argv[1]);   									//a call to the library file using the command line arguement for the file name
	int HiddenWord = ChooseRandomWord(); 								//it is returned an int since the word is a global variable anyways, we just need a random number
	int attempts = 8, i = 0, length, answer = 0, correct = 0, j, k, l;  				//decleration
	length = strlen(Words[HiddenWord]);								//get the length of the word
	char guess;											//creating a variable for the guessed letter
	char guessing[40];										//the character array to show what the user has guessed so far
	for(l = 0; l < length; l++)
		guessing[l] = '-';
	guessing[length] = '\0';									//sets the null terminator where the array should end (I don't know how to make a dynamic array)
	printf("Welcome to Hangman!");
	printf("I will guess a secret word. On each turn, you guessa letter.\nIf the letter is in the secret word, I will show you where it appears;\nif not, a part of your body gets strung up on the scaffold.\nTheobject is to guess the word before you are hung.");
	for(i = 0; i < length; i++){									//set the letters to uppercase
		if(Words[HiddenWord][i] >= 97 && Words[HiddenWord][i] <= 122)				
			Words[HiddenWord][i] -= 32;
	}
	while(attempts > 0 || correct != length){   							//this while loop doesn't break for some reason, just keeps on going
		int within = 0, duplicate = 0;								//declaration
		printf("The word now looks like this %s\nYou have %d guesses left\nGuess a letter: ", guessing, attempts);
		scanf("%c%*c", &guess);									//user input guess
		if(guess >= 97 && guess <= 122)								//sets the guess to uppercase
			guess -= 32;
		for(i = 0; i < length; i++){								//checks if the user already guessed the same letter, no penalty if they did
			if(guessing[i] == guess){
				printf("You already guessed %c\n", guess);
				duplicate = 1;
			}
		}
		for(i = 0; i < length; i++){								//checks if the guessed letter is within the word
			if(Words[HiddenWord][i] == guess && duplicate == 0){
				guessing[i] = guess;
				within = 1;
				correct += 1;
			}
		}
		if(within == 1)										//if the letter is within, inform the user
			printf("That guess is correct.\n");
		else if(duplicate == 0){
			printf("There are no %c's in the word\n", guess);				//if the letter is not apart of it, update the counter and inform the user
			attempts -= 1;
		}
	if(correct == length)										//I had to use these breaks since the while loop didn't break for some reason
		break;
	if(attempts == 0)
		break;
	}
	if(attempts == 0)										//informs the user is they won or lost
		printf("You did not correctly guess the word within the given attempts\n");
	else
		printf("You guessed the word: %s\n You win.\n", guessing);
}
