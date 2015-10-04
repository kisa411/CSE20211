#include <stdio.h>
#include <math.h>

int main (void)
{
    double principal, interest, monthlyPayment;
    double remainingBalance; 
    int years, months, month;
    
    //ask user for input values;
    printf("What's the principal?\n");
    scanf("%lf", &principal);
    printf("What's the interest rate?\n");
    scanf("%lf", &interest);
    printf("What's the desired monthly payment amount?\n");
    scanf("%lf", &monthlyPayment);
    

    //check to make sure the inputs are valid
    if (principal <=0 || interest <=0 || monthlyPayment <=0) {
        printf("Please recheck your inputs for the values of principal, interest rate, and desired monthly payment. Make sure the interest rate is given in decimal format!\n");
    }
    
    //print out headers
    printf("Month\tPayment\t\tInterest\tBalance\n");
   
    remainingBalance = principal;
    double total = 0.0;
     
    while (remainingBalance>0.0) {
        double newInterest = ((interest / 100.0 * remainingBalance)/12.0);
        
             
        //check that the remaining balance will not become negative    
        if (remainingBalance - (monthlyPayment + newInterest) <= 0.0) {
            monthlyPayment = remainingBalance;
            remainingBalance = 0.0;
        } else {
        remainingBalance = remainingBalance - monthlyPayment + newInterest;
        
        //make sure that the remaining balance doesn't increase if monthly payment is too small
        if (remainingBalance >= principal) {
            printf("Your monthly payment amount is too low.\n");
            printf("Please re-input the amount you are paying per month.\n");
            break;
        }
        }
        
        
        //print out the different values
        month++;
        printf ("%d\t", month);
        printf ("$%5.2lf\t\t", monthlyPayment);
        printf ("$%.2lf\t\t", newInterest);
        printf ("$%.2lf\n", remainingBalance);
        
        total += monthlyPayment;
        
        //if
       
        }   
        
   
    years = (month/12);
    months = month - (years*12);
    
    //print out the total amount paid and the time it took to pay it off
    printf("You paid a total sum of $%lf over %d years and %d months.", total, years, months);
 
    
    return 0;
}
   
            
        