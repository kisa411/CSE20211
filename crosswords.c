#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SUCCESS 0
#define FAILURE 1
#define VERTICAL 0
#define HORIZONTAL 1



//function prototypes
struct Clues {
	int row;
	int column;
    int axis; //0 = down, 1 = across
    char anagramclue[16];
};

int storewords(char arr[][16]);
void sortwords(char arr[][16], int size);
void capitalizewords(char words[][16], int size);
void printboard(char board[][15]);
void printclues(struct Clues cluelist[20], int size);
void printsolution(char board[][15]);
void placedown(int row, int col, char board[15][15], char word[16], int k);
void placeacross(int row, int col, char board[15][15], char word[16], int k);
int isvaliddown(int row, int col, char board[15][15], char word[16]);
int isvalidacross(int row, int col, char board[15][15], char word[16]);
void initializeboard(char board[][15]);
void makeclue(int row, int col, char word[], struct Clues *cluelist, int orientation);


/*------------------------------------------------------------------------------
----------------*/
int main() {
    char words[20][16], board[15][15]; //the size of the crossword board will be 15 rows x 15 columns
    int i, j, size, k, colpos, row, col, x, y, orientation, cl=0;
        //initialize the board to all 0s
    initializeboard(board);

    size = storewords(words);

    struct Clues cluelist[size]; //initialize array of struct members


    sortwords(words, size); //sort the 2D array; passes by reference since it's an array

    capitalizewords(words, size);

    //place first, longest word
    colpos=(15-strlen(words[size-1]))/2;
    placeacross(7, colpos, board, words[size-1], (size-1));
    makeclue(7, colpos, words[size-1], &cluelist[0], HORIZONTAL);

    //place other words, starting at longest words first
    for (k=size-2; k>=0; k--) {
    	for (row=0; row<15; row++) {
    		for (col=0; col<15; col++) {
    			x=isvaliddown(row, col, board, words[k]);
    			y=isvalidacross(row, col, board, words[k]);
    			if (x==SUCCESS) {
    				placedown(row, col, board, words[k], k);
    				cl++;
    				makeclue(row, col, words[k], &cluelist[cl], VERTICAL);
	                row=15; //kicks out of both for loops
	                col=15;
	            }
	            else if (y==SUCCESS) {
		           	placeacross(row, col, board, words[k], k);
		           	cl++;
		           	makeclue(row, col, words[k], &cluelist[cl], HORIZONTAL);
	                row=15; //kicks out of both for loops
	                col=15;
	            }
				if (row==14 && col==14 && x==FAILURE && y==FAILURE) {
			        printf("%s couldn’t be placed.\n", words[k]);
       			}
   			}
		}
    }

	printboard(board);

	printclues(cluelist, cl+1);

	printsolution(board);


    return 0;
}

/*------------------------------------------------------------------------------
----------------*/
//places word down at position row, col on current board
void placedown(int row, int col, char board[15][15], char word[16], int k) {

	int i;

	for (i=0; i<strlen(word); i++) {
		board[row+i][col]=word[i];
	}

	if (row==0) {
		board[row+strlen(word)][col] = 1;
	} else if (row==14) {
		board[row-1][col] = 1;
	} else {
		board[row-1][col] = 1;
		board[row+strlen(word)][col] = 1;
	}

}

//places word across at position row, col on current board
void placeacross(int row, int col, char board[15][15], char word[16], int k) {

	int i;

	for (i=0; i<strlen(word); i++) {
		board[row][col+i]=word[i];
	}

	if (col==0) {
		board[row][col+strlen(word)] = 1;
	} else if (col==14) {
		board[row][col-1] = 1;
	} else {
		board[row][col-1] = 1;
		board[row][col+strlen(word)] = 1;
	}

}

//function to determine if down at starting position row and col is valid
int isvaliddown(int row, int col, char board[15][15], char word[16]) {
    //if valid, return SUCCESS; if invalid, return FAILURE

	int i, j, on=0, length=strlen(word), irow, icol;
	char boardcp[15][15];


    //make a copy of the board so you dont overwrite original gameboard
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			boardcp[i][j] = board[i][j];
		}
	}

    //if all spaces values are 0, invalid position since you want it to find an intersecting letter
	for (i=0; i<length; i++) {
        if ((row+i)>=15) { //if the length of the word is longer than there are enough rows for, invalid position
        	return FAILURE;
        }
        if (boardcp[row+i][col]==0) { //increment 'on' for each empty space that there is
        	on++;
    	} 
    	if (boardcp[row+i][col]==1) {
    		return FAILURE;
    	}
	}

        if (length==on) { //if there are no intersecting letters for the entirelength of the word, then invalid position
        	return FAILURE;
        }

        //other conditions to check if position is valid
        for (i=0; i<length; i++) {
        	if (boardcp[row+i][col]==0) { //if the space is empty, then go ahead and print the word
        		boardcp[row+i][col]=word[i];
       		 }

		    else if (boardcp[row+i][col] == word[i]) { //if while printing the word,there is another character in the next space, if the space contains an intersecting letter that is the same, then go ahead and keep printing out the word

		    	boardcp[row+i][col]=word[i];
                irow=row+i; //store the intersection row
                icol=col; //store the intersection col
            }
            else {
		       return FAILURE;  //word cannot be placed in this position
		   }

   		}

 //check around the word so that it's not right next to another one

    //check for words next to eachother
    //check all 4 corners first
    if (irow==0 && icol==0) {  //top right
    	if (boardcp[irow+1][icol+1] != 0) {
    		return FAILURE;
    	}
    }
    else if (irow==0 && icol==14) {  //top left
    	if (boardcp[irow+1][icol-1] != 0) {
    		return FAILURE;
    	}
    }
    else if (irow==14 && icol==0) {   //bottom right
    	if (boardcp[irow-1][icol+1] != 0) {
    		return FAILURE;
    	}
    }
    else if (irow==14 && icol==14) {   //bottom left
    	if (boardcp[irow-1][icol-1] != 0) {
    		return FAILURE;
    	}
    }

    //check edges
    if (irow==0) {   //top row
    	if (boardcp[irow+1][icol-1]!=0 || boardcp[irow+1][icol+1]!=0) {
    		return FAILURE;
    	}
    }
    else if (irow==14) {  //bottom row
    	if (boardcp[irow-1][icol-1]!=0 || boardcp[irow-1][icol+1]!=0) {
    		return FAILURE;
    	}
    }
    else if (icol==0) {   //left col
    	if (boardcp[irow+1][icol+1]!=0 || boardcp[irow-1][icol+1]!=0) {
    		return FAILURE;
    	}
    }
    else if (icol==14) {   //right col
    	if (boardcp[irow-1][icol-1]!=0 || boardcp[irow+1][icol-1]!=0) {
    		return FAILURE;
    	}
    }

    //check middle spaces
    if (boardcp[irow-1][icol-1]!=0 || boardcp[irow-1][icol+1]!=0 || boardcp[irow+1][icol-1]!=0 || boardcp[irow+1][icol+1]!=0 ) {
    	return FAILURE;
    }


    //check ends of word
    if (boardcp[row-1][col]!=0) {
    	return FAILURE;
    }
    else if (boardcp[row+length][col]!=0) {
    	return FAILURE;
    }

    //if not invalid, return SUCCESS
    return SUCCESS;
}


//same thing as isvaliddown but for placing words across
int isvalidacross(int row, int col, char board[15][15], char word[16]) {

	char boardcp[15][15];
	int i, j, on=0, length=strlen(word), irow, icol;

	 //make a copy of the board so you dont overwrite original gameboard
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			boardcp[i][j] = board[i][j];
		}
	}

    //if all spaces values are 0, invalid position since you want it to find an intersecting letter
	for (i=0; i<length; i++) {
       if ((col+i)>=15) { //if the length of the word is longer than there are enough columns for, invalid position
       		return FAILURE;
       }
       if (boardcp[row][col+i]==0) { //increment on for each empty space that there is
       		on++;
       } 
       if (boardcp[row][col+i]==1) {
       		return FAILURE;
       }
   	}

    if (length==on) { //if there are no intersecting letters for the entire length of the word, then invalid position
    	return FAILURE;
    }


    for (i=0; i<length; i++) {
        if (boardcp[row][col+i]==0) { //if the space is empty, then go ahead and print the word
        	boardcp[row][col+i]=word[i];
        }
        else if (boardcp[row][col+i] == word[i]) { //if while printing the word, there is another character in the next space, if the space contains an intersecting letter that is the same, then go ahead and keep printing out the word
        	boardcp[row][col+i]=word[i];
            irow=row; //store the intersection row
            icol=col+i; //store the intersection col
        }
        else {
        	return FAILURE;  //word cannot be placed in this position
        }
    }


    //check for words next to eachother
    //check all 4 corners first
    if (irow==0 && icol==0) {  //top right
    	if (boardcp[irow+1][icol+1] != 0) {
    		return FAILURE;
    	}
    }
    else if (irow==0 && icol==14) {  //top left
    	if (boardcp[irow+1][icol-1] != 0) {
    		return FAILURE;
    	}
    }
    else if (irow==14 && icol==0) {   //bottom right
    	if (boardcp[irow-1][icol+1] != 0) {
    		return FAILURE;
    	}
    }
    else if (irow==14 && icol==14) {   //bottom left
    	if (boardcp[irow-1][icol-1] != 0) {
    		return FAILURE;
    	}
    }

    //check edges
    if (irow==0) {   //top row
    	if (boardcp[irow+1][icol-1]!=0 || boardcp[irow+1][icol+1]!=0) {
    		return FAILURE;
    	}
    }
    else if (irow==14) {  //bottom row
    	if (boardcp[irow-1][icol-1]!=0 || boardcp[irow-1][icol+1]!=0) {
    		return FAILURE;
    	}
    }
    else if (icol==0) {   //left col
    	if (boardcp[irow+1][icol+1]!=0 || boardcp[irow-1][icol+1]!=0) {
    		return FAILURE;
    	}
    }
    else if (icol==14) {   //right col
    	if (boardcp[irow-1][icol-1]!=0 || boardcp[irow+1][icol-1]!=0) {
    		return FAILURE;
    	}
    }

    //check middle spaces
    if (boardcp[irow-1][icol-1]!=0 || boardcp[irow-1][icol+1]!=0 || boardcp[irow+1][icol-1]!=0 || boardcp[irow+1][icol+1]!=0 ) {
    	return FAILURE;
    }

    //check ends of word
    if (boardcp[row][col-1]!=0) {
    	return FAILURE;
    }
    else if (boardcp[row][col+length]!=0) {
    	return FAILURE;
    }

    //if not invalid, return SUCCESS
    return SUCCESS;


}


//print solution board - function to show solution
void printsolution(char board[15][15]) {
	int i, j;

	printf("SOLUTION\n");

	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			if (board[i][j] == 0 || board[i][j] == 1) {
				printf("%c", '.');
			} 
			else {
				printf("%c", board[i][j]);
			}
            if (j==14) {   //prints new line when it reaches 15 characters
         	    printf("\n");
            }
        }
    } printf("\n");

}


//initializes board with all 0s
void initializeboard(char board[][15]) {

	int i, j;

	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			board[i][j]=0;
		}
	}
}

//function to store all the words in a 2D array
int storewords(char words[20][16]) {
	int size = 0;
	char word[16];

	printf("Enter a list of up to 20 words (or less) of up to 16 letters each. If you put in less than 20 words then put in a . to signify the end of the input.\n");

	do {
		scanf("%15s", word);
		if(strcmp(word, ".") == 0)
			break;
        strcpy(words[size], word); //copy word (string) into 2d array
        size++;
    } while (size < 20);

    return size;
}

//function to sort words in array
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
} //longest word is now arr[size]

//function to put words on board & designate location & make anagram clues
void capitalizewords(char words[][16], int size) {
	int i, j, row, col;

	for (i=0; i<size; i++) {
		for (j=0; j<strlen(words[i]); j++) {
                        words[i][j] = toupper(words[i][j]); //convert all the letters to uppercase letters in the 2D array
                    }
                }
            }


//print solution board - function to print puzzle
void printboard(char board[15][15]) {
   	int i, j;

   	printf("PUZZLE\n");

    for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			if (board[i][j] == 0 || board[i][j] == 1) {
				printf("%c", '#');
			}
			else {
				printf("%c", ' ');
			}
    		if (j == 14) { //prints new line when it reaches 15
        	printf("\n");
        }
    }
    }printf("\n");

}


//function to print the clues - row, column, axis, anagram
void printclues(struct Clues cluelist[20], int size) {
	int i;

	printf("CLUES\n");

	for (i=0; i<size; i++) {
		printf("%5d, %5d", cluelist[i].row, cluelist[i].column);
		if (cluelist[i].axis == 0) {
			printf("    DOWN");
		} else {
			printf("  ACROSS");
		}
		printf("%16s\n", cluelist[i].anagramclue);
	}

	printf("\n");
}

void makeclue(int row, int col, char word[], struct Clues *cluelist, int orientation) {

	cluelist->row=row+1;
	cluelist->column=col+1;
	cluelist->axis=orientation;
    strcpy(cluelist->anagramclue, strfry(word));
}
