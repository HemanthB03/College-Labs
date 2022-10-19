#include <stdio.h>

int main() {
	int arr[20], n, i, search, flag, pos;

	printf("Enter the number of elements(<=20): ");
	scanf("%d", &n);

	printf("Enter the elements of array: ");
	for(i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter element to search: ");
	scanf("%d", &search);

	printf("Starting linear search.........\n");

	flag=0;
	for(i=0; i<n; i++) {
		if(arr[i]==search) {
			flag=1;
			pos=i+1;
			break;
		}
	}

	if(flag==1) {
		printf("%d found at position %d (index==%d)\n", search, pos, i);
	}
	else {
		printf("%d not found in array\n", search);
	}

	return 0;
}