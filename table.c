/* Emily Koh
FCI 
Lab 2 Part 1 */

#include <stdio.h>

int main (void)
{
    int tablerow;
    int tablecolumn;
    int i;
    int j;
    
    //ask user for input for table size
    printf("What should the number of rows be?\n");
    scanf("%d", &tablerow);
    
    printf("What should the number of columns be?\n");
    scanf("%d", &tablecolumn);
    
    printf("    *");
        
    //make columns of tables
    for (i=1; i <= tablecolumn; i++) {
        printf("%5d", i);
    }
    printf("\n");

    //make multiplication values
    for (i=1; i <= tablerow; i++) {
        printf("%5d", i);
            for (j=1; j<= tablecolumn; j++) {
                printf("%5d", i*j);
    }
    printf("\n");
    }
    return 0;
}



