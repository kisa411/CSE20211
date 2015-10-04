# include <stdio.h>

int main(void) {
    int number, counter, i;
    counter = 1;
    number = 1;
    
    //check divisibility rules
    for (i = 0; i < 999999999; i++) {
        counter += 1;
        if (counter % 2 == 0) {
            continue;
        } else if (counter % 3 == 0) {
            continue;
        } else if (counter % 4 == 0) {
            continue;
        } else if (counter % 5 == 0) {
            continue;
        } else if (counter % 6 == 0) {
            continue;
        } else if (counter % 7 == 0) {
            continue;
        } else if (counter % 8 == 0) {
            continue;
        } else if (counter % 9 == 0) {
            continue;
        } 
    
        if (counter > number) {
            number = counter;
        }
    }
    
    printf("The biggest pandigital number is %d\n", number);
    
    return 0;
}