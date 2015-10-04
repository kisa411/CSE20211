/* Emily Koh
FCI
Lab 4 - Part 2*/

#include <stdio.h>

int main() {
    int i, j, numbers[1000];
    int values[1000];
    
    //if index value is prime, then set it to 1; otherwise set it to 0
    //set all elements of array to 1
    for (i = 2; i < 1000; i++) {
        numbers[i] = 1;
    }
    //set the first two numbers (0 and 1) to 0 since they're not prime
    numbers[0] = 0; numbers[1] = 0;
    
    //loop through rest of values and only set prime numbers to 1
    for (i = 2; i < 1000; i++) {
         for (j = i*i; j<1000; j+=i) {
            numbers[j] = 0;
        } 
    //print out the prime numbers
    if (numbers[i] == 1) {
        printf("%5d", i);
    }
    }
    
    printf("\n");
   

    return 0;
}


  /*(The Sieve of Eratosthenes) A prime integer is any integer greater than 1 that can be divided evenly only by itself and 1. The Sieve of Eratosthenes is a method of finding prime numbers. It works as follows:

a) Create an array with all elements initialized to 1 (true). Array elements with prime subscripts will remain 1. All other array elements will eventually be set to zero.

b) Starting with array subscript 2 (subscript 1 is not prime), every time an array element is found whose value is 1, loop through the 
remainder of the array and set to zero every element whose subscript is a multiple of the subscript for the element with value 1. For array subscript 2, all elements beyond 2
 in the array that are multiples of 2 will be set to zero (subscripts 4, 6, 8, 10, and so on.). 
For array subscript 3, all elements beyond 3 in the array that are multiples of 3 will be set to zero (subscripts 6, 9, 12, 15, and so on.). 
When this process is complete, the array elements that are still set to 1 indicate that the subscript is a prime number.
 Write a program that uses an array of 1000 elements to determine and print the prime numbers between 1 and 999. Ignore element 0 of the array.*/
































