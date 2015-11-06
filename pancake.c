#include <stdio.h>

void flip(int* arr);

int main() {
	int i, number;
	int stack[5]; //define array 'stack'

	printf("Please put in the stack values:"); //get user input into array
	
	for (i=0; i < 5; i++) {
			scanf("%d", stack[i]); //put or read user input into array
			printf("The stack values are %d", stack); //print out given values to make sure they're correct
	}

	
	//call function
	flip(stack);

	return 0;
}

void flip(int* arr) {
	int i, j, reverse;
	int count;

	//compare the values and see if they're in sequential order
	for(i = 0; i < 4; i++) {
		count = 0;
		if (arr[i] <= arr[i+1]) {
			continue;
		} else if (arr[i] > arr[i+1]) {
			for(j=i; j < (sizeof(arr)/sizeof(int))-i; j++) {
				reverse = arr[j]%10;    //reverse numbers
				count+=1; 
				printf("%d", reverse);
			} printf("\n");
			printf("flip(%d)", count);
		} 
	}

}