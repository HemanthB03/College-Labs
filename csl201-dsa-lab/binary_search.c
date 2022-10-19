#include <stdio.h>

int main() {
    int arr[20], n, i, key, flag, pos, first, last, mid;

    printf("Enter the number of elements(<=20): ");
    scanf("%d", &n);

    printf("Enter the elements of array in ascending order: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Starting binary search.........\n");

    flag=0;
    first=0;
    last=n-1;
    while(first<last) {
        mid=(first+last)/2;
        if(arr[mid]==key) {
            flag=1;
            pos=mid+1;
            break;
        }
        else if(arr[mid]<key) {
            first=mid+1;
        }
        else {
            last=mid-1;
        }
    }

    if(flag==1) {
        printf("%d found at position %d (index==%d)\n", key, pos, mid);
    }
    else {
        printf("%d not found in the array\n", key);
    }

    return 0;
}