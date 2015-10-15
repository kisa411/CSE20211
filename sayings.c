#define _GNU_SOURCE


#include <stdio.h>
#include <string.h>


// void scan(FILE*);


int main(){
	char sayings[100][80], emptycharacter;
	char saying[80], temp[80], query[20], newname[20], filename[20];
	int userInput, i;
	int numberOfSayings = 0;

	printf("What's the name of the startup data file? ");
	scanf("%s", filename);

	//opens the file using fopen (FILE = type of variable *filepointer) - filepointer now points to the address of the given filename
	FILE *filepointer = fopen(filename, "r");
	if (filepointer == NULL) {
		printf("File is not valid, cannot be read\n");
	}


	while (!feof(filepointer)) { //feof = checks if given parameter is currently at end of file
		fgets(sayings[numberOfSayings], 80, filepointer); //includes newline character and automaticallly appends terminating null character
		numberOfSayings++;

	}

	//menu of options
	printf("Choose one of the following options:\n 1.Displaying all sayings currently in the database. \n 2. Enter a new saying into the database.\n 3. List sayings that contain the given word (substring) entered by the user.\n 4. Save all sayings in a new text file.\n 5. Quit the program.\n");
	

	do { //ask for user input at least once, then go into switch statement
		printf("What do you want to do now? ");
		scanf("%d", &userInput);

		switch (userInput) {
			case 1: 
				//display all sayings currently in database

				for (i = 0; i < numberOfSayings; i++) {
					
					printf("%s", sayings[i]);
				}  //will print out sayings by row
		

				break;
			case 2:
				//enter a new saying into the database
				printf("Enter the new saying you want to add:\n");
				// scanf("%s", temp);
				scanf("%c", &emptycharacter); //capture newline input from keyboard

				fgets(sayings[numberOfSayings], 80, stdin); //read input from standard input (string is at max 80 characters long) and put it into temp array

				printf("%s\n", sayings[numberOfSayings]);

				//put new saying into next open row in 2D array saying
				// strcpy(sayings[numberOfSayings + 1], temp); //copy string from temp into sayings array at new open row
				numberOfSayings++;
				break;
			case 3:
				//list sayings that contain a given word entered by user
				printf("What's the word you're looking for?\n");
				scanf("%s", query);

				//look for search query in the sayings 2D array - find the first occurrence of query in sayings, ignore case
				for (i=0; i < numberOfSayings; i++) {
					if (strcasestr(sayings[i], query) != NULL) {
						printf("%s", sayings[i]);
					}
				}
				break;
			case 4:
				//take in user-input about file name
				printf("What do you want the new file to be called?\n");
				scanf("%s", newname);

				FILE *newfilepointer = fopen(newname, "w+"); //creates file pointer, w+ creates an empty file and opens it for update (if file already exists)

				//save sayings array to the new file
				for(i = 0; i<numberOfSayings; i++){
					fputs(sayings[i], newfilepointer);
				}
				break;
			case 5:
				userInput = -1;
				break;
			default:
				printf("Please put in a valid input\n");

				//re-prompt user for correct input
				printf("Choose one of the following options:\n 1.Displaying all sayings currently in the database.\n 2. Enter a new saying into the database.\n 3. List sayings that contain the given word (substring) entered by the user.\n 4. Save all sayings in a new text file.\n 5. Quit the program.\n");
				continue; //go back up to do loop and re-prompt for userinput
 		} 
	} while (userInput > 0);
	

	return 0;
}



