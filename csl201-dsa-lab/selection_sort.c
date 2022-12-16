#include <stdio.h>

int main() {
    int arr[20], n, i, j, loc, min;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n; i++) {
        min=arr[i];
        loc=i;
        for(j=i+1; j<n; j++) {
            if(arr[j]<min) {
                min=arr[j];
                loc=j;
            }
        }
        arr[loc]=arr[i];
        arr[i]=min;
    }

    printf("The sorted array is\n");
    for(i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;

}