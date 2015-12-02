#include <stdio.h>
#include <string.h>
#include <ctype.h>


void sortwords(char arr[][16], int size);
void printclues(char arr[][16], int size);
void printboard(char arr[][16], int size);

int main () {
	char words[20][16], word[16];
	int i, j, size=0;

	printf("Enter a list of up to 20 words (or less) of up to 15 letters each. If you put in less than 20 words then put in a '.' to signfy the end of the input.\n");
	
	scanf("%15s", word);

	while (strcmp(word, ".") != 0 && (size < 20)) { //ask user for input, get list of words
		

		strcpy(words[size], word); //copy word (string) into 2d array
		size++;
		scanf("%15s", word);
		printf("Scanned word %s\n", word);
	}

	do {
		scanf("%15s", word);
		if(strcmp(word, ".") == 0)
			break;
		strcpy(words[size], word); //copy word (string) into 2d array
		size++;
	} while (size < 20);

	printf("%d\n", size);

	for (i=0; i<size; i++) { //try printing out updated 2D array
		printf("%s\n", words[i]);

	} printf("array with all the words\n");

	sortwords(words, size);

	for (i=0; i<size; i++) { //try printing out updated 2D array
		printf("%s\n", words[i]);
	} printf("array with sorted words\n");

	printboard(words, size);

	for (i=0; i<size; i++) { //try printing out updated 2D array
		printf("%s\n", words[i]);
	} printf("array with uppercase words\n");


	// for (i=0; i<=15; i++) { //try printing out updated 2D array
	// 	printf("%s\n", board[i]);
	// } printf("puzzle board\n");


	return 0;
}

void sortwords(char arr[][16], int size) {
	char temporary[16];
	int i, j;

	for (i=0; i < (size-1); i++) {
		for (j=0; j<(size-i-1); j++) {
			if (strlen(arr[j]) > strlen(arr[j+1])) {
				strcpy(temporary, arr[j+1]);
				strcpy(arr[j+1], arr[j]);
				strcpy(arr[j], temporary);
			}
		}
	}
}



void printboard(char arr[][16], int size) {
	char board[15][15]; //the size of the crossword board will be 15 rows x 15 columns
	int i, j;

	for (i=0; i<size; i++) {
		for (j=0; j<strlen(arr[i]); j++) {
			arr[i][j] = toupper(arr[i][j]); //convert all the letters to uppercase letters in the 2D array
		}
	}

	//print puzzle board - function to place all the words and put blank spots 


	//print solution board - function to place all the words and show solution

}

/*---------------------------------------------------*/
//validation function
void isValid();











