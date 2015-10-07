#include <stdio.h>

int factorial(int);
int total(int);

int main(){
	int i, maximum, number;

	printf("What do you want the maximum number to be?");
	scanf("%d", &number);

	for (i=0; i<=number; i++) {
		if (factorial(i) == total(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}

int factorial(int a){
	int value = 1, i, digit = 0, sum = 0;

	while (a>0){
		digit = a%10;
		a = a/10;
		for (i=digit; i>0; i--){
			value *= i;
		}
		sum += value;
	}
	return sum;
}

int total(int a) {
	int sum = 0, digit = 0;

	while(a>0) {
		digit = a%10;
		a = a/10;
		sum += digit;
	}
	return sum;
}