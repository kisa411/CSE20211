/*Emily Koh
FCI
Lab 4 - Part 3*/

#include <stdio.h>

void win_year(void);
void loss_year(void);
void tied_year(void);
void specific_year(int i);

int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9, 8 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4, 5 };
   
int main() {
    int user_input, year;
    
    //user prompts
    printf("What question would you like an answer to?\n");
    printf(" 1. Years in which ND won at least 5 games.\n 2. Years in which ND lost at least 5 games.\n 3. Years in which ND tied.\n 4. Number of wins or losses for a particular year.\n");
    scanf("%d", &user_input);

int condition = 5;    
while (condition == 5) {
    if (user_input == 1) {
        win_year();
    } else if (user_input == 2) {
        loss_year();
    } else if (user_input == 3) {
        tied_year();
    } else if (user_input == 4) {
        printf("What year would you like to know about?\n");
        scanf("%d", &year);
        specific_year(year);
    } else {
        printf("Please enter a valid choice.");
        scanf("%d\n", &user_input);
        continue;
    }
    break;
}

    return 0;
}

//function to tell you the years in which at least 5 games were won
void win_year() {
    int i;
    
    //sizeof = takes the size of things
    for (i=0; i < sizeof(wins)/sizeof(int); i++) {
        if (wins[i] >= 5) {
            printf("Here are the years:");
            printf(" %d\n", i + 1900);
        }
    }
    printf("\n");

}

//function to tell you the years in which at least 5 games were lost  
void loss_year() {
    int i;
    
    for (i=0; i< sizeof(wins)/sizeof(int); i++) {
        if (losses[i] >= 5) {
            printf("Here are the years:");
            printf(" %d\n", i + 1900);
        }
    }
    printf("\n");
    
}

//function to tell you the years in which there was a tie 
void tied_year() {
    int i;
    
    for (i=0; i< sizeof(wins)/sizeof(int); i++) {
        if (losses[i] == wins[i]) {
            printf("Here are the years:");
            printf(" %d\n", i + 1900);
        }
    }
    printf("\n");

}
    
//function to tell you the stats for a specific year
void specific_year(int i) {
    i = i - 1900;

    if (i >= (sizeof(wins)/sizeof(int)) || i < 0) {
        printf("Stats don't exist for that year.\n");
    } else if (wins[i] != losses[i]) {
        printf("%d wins and %d losses.\n", wins[i], losses[i]);
    } else {
        printf("There was a tie for that year.\n");
    }  

}
     