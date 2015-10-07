#include <stdio.h>
void getfreq(int[], int);

int main() {
	int array[] = {1,3,5,6,7};
	int size = 5;

	
	getfreq(array, size);
	
	return 0;
}

void getfreq(int arr[], int size){
	int count[10]={0};
	int i,j;

	for(i=0; i<size; i++){
		for(j=0; j<10; j++) {
			if (arr[i]==j){
			count[j]++;
			}
		}
	}

	for (i=0; i<10; i++) {
		printf("digit %d occurs %d times\n", i, count[i]);
	}
}
