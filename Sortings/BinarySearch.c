#include <stdio.h>
#include <stdlib.h>

int binSearch(int arr[],int l,int h,int x) {
    if (l <= h) {
        int mid=l+(h-l)/2;
        if (arr[mid]==x) {
            return mid;
        }
        if (arr[mid]>x) {
            return binSearch(arr,l,mid-1,x);
        } else {
            return binSearch(arr,mid+1,h,x);
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of arr: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("Please enter a valid size.\n");
        return 1;
    }
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the arr in sorted order: ");
    for (int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Element to find: ");
    scanf("%d", &x);
    int index = binarySearch(arr,0,n-1,x);
    if (index!=-1) {
        printf("Element %d found at index %d.\n", x, index);
    } else {
        printf("Element %d not found in the array.\n", x);
    }
    free(arr);
    return 0;
}
