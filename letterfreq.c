#include <stdio.h>
#include <ctype.h>

int main () {
	int counter[26] = {0}, total, i; //{} sets all the values in array to 0, not putting {} sets the first index of the array to 0, since array is pointer
	char file[50]; //make file an array since a string is an array of characters
	double spacePercentage, whiteSpace, characters;

	//read file from user
	printf("What's the name of the file?");
	scanf("%s", file); //gets the name of the file


	FILE* filePointer = fopen(file, "r"); //fopen = returns the address of the file with the string name that was given, r = reads file at location of pointer
	//assign file pointer (FILE*) to the returned address

	char a;
	char letter = fgetc(filePointer); //fgetc uses the returned address to start reading file

	total = 0;
	characters = 0;
	whiteSpace = 0;

	while (letter!=EOF) {  //Assign variable letter to each letter read from the file, EOF = end of file
		if (isalpha(letter)) {  //if the letter read is a letter
			if (islower(letter)) {  //if the letter read is lowercase
				counter[letter-97]++;
			} else {                //if the letter read is uppercase
				counter[letter-65]++;
			}
			total++;
		} else if (isspace(letter)) { //if the letter read is a whitespace
			whiteSpace++;
		}
		characters++;
		letter = fgetc(filePointer); //calls on fgetc until end of file - requires reassignment to letter to get the next letter
	}

	spacePercentage = (whiteSpace)/(characters);

	for (i = 0; i < 26; i++) {
		printf("%c : %d \n", 'a' + i, counter[i]); //%c - prints out the character, loops through ASCII table values and then prints appropriate character

	} 

	printf("There were %d letters\n", total);
	printf("There were %.0lf total characters\n", characters);
	printf("There were %.0lf white space characters\n", whiteSpace);
	printf("Space Percentage:%0.2lf%%\n", spacePercentage);

	return 0;
}