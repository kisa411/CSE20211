
/* Emily Koh
FCI
Lab 3 Part 3 - text menu calculator */

#include <stdio.h>

int main (void)
{
    int userInput, a, b, c;
    
    //ask user what mathematical operation they'd like to perform
    printf("What mathematical operation would you like to perform?\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Quit\n");
    scanf("%d", &userInput);
    
    
    //depending on user input, function called will be different
    while (userInput <=5) {    
        switch(userInput) {
            case 1:
                //addition
                printf("Enter two integers:");
                scanf("%d %d", &a, &b);
                printf ("The answer is: %d\n",(a + b));
                printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n$
                scanf("%d", &userInput);
                break;
            case 2:
                //subtraction
                printf("Enter two integers:");
                scanf("%d %d", &a, &b);
                printf ("The answer is: %d\n",(a - b));
                printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n$
                scanf("%d", &userInput);
                break;
            case 3:
                //multiplication
                printf("Enter two integers:");
                scanf("%d %d", &a, &b);
                printf ("The answer is: %d\n",(a*b));
                printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n$
                scanf("%d", &userInput);
                break;
            case 4:
                //division
                printf("Enter two integers:");
                scanf("%d %d", &a, &b);
                printf ("The answer is: %d\n",(a/b));
                printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n$
                scanf("%d", &userInput);
                break;
            case 5:
                //end loop
                printf("Program will end.\n");
                userInput = 6;
                break;
        }
    }
    
    return 0;
}



