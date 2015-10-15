#include <stdio.h>

void flip(int* arr);

int main() {
	int i, number;
	int stack[5]; 

	printf("Please put in the stack values:"); //get user input into array
	scanf("%d", &number);
	

	while (scanf("%d", stack) > 0 ) {//!= EOF) {
		for (i=0; i < 5; i++) {
			stack[i] = number;
			scanf("%d", &number); //put or read user input into array
		}
	}

	
	//call function
	flip(stack);

	return 0;
}

void flip(int* arr) {
	int i, j, reverse;
	int count = 0;

	//compare the values and see if they're in sequential order
	for(i = 1; i < sizeof(arr)/sizeof(int); i++) {
		count = 0;
		if (arr[i] >= arr[i-1]) {
			printf("%d %d", arr[i-1], arr[i]);
			continue;
		} else if (arr[i] < arr[i-1]) {
			for(j=i; j < (sizeof(arr)/sizeof(int))-i; j++) {
				reverse = arr[j]%10;    //reverse numbers
				count+=1; 
				printf("%d", reverse);
			} printf("\n");
			printf("flip(%d)", count);
		} 
	}

}