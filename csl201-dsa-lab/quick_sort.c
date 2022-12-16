#include <stdio.h>

int arr[20], n, mid, temp;

int partition(int low, int high) {
    int i=low, j=high, x=arr[low];
    while(i<=j) {
        while(arr[i]<=x && i<n) {
            i++;
        }
        while(arr[j]>x && j>=0) {
            j--;
        }
        if(i<j) {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else {
            temp=arr[j];
            arr[j]=arr[low];
            arr[low]=temp;
        }
    }
    return j;
}

void quick_sort(int low, int high) {
    if(low<high) {
        mid=partition(low, high);
        quick_sort(low, mid-1);
        quick_sort(mid+1, high);
    }
}

int main() {
    int i;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(0, n-1);

    printf("The sorted array is\n");
    for(i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;

}