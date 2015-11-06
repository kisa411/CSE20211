//code doesn't work

#include <stdio.h>

int main() {
	int i, j, numbers[10], counter[10] = {0};

	printf("Type in 10 numbers: ");
	
	for (i=0; i<10; i++) {
		scanf("%d", &numbers[i]);
	}

	i = 0;

	for (j=0; j<10; j++) {
		if (numbers[i] == j) {
			counter[j]++;
			i++;
		}
	}

	for (j=0; j<10; j++) {
		printf("The count of digits is %d: %d\n", j, counter[j]);
	}

	return 0;
}