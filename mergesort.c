#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void merge(int arr[], int lb, int mid, int ub) {

    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[100];

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
            k++;
        } else {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i > mid) {
        while (j <= ub) {
            b[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for (k = lb; k <= ub; k++) {
        arr[k] = b[k];
    }
}

void mergesort(int arr[], int lb, int ub) {
    int mid;
    if (lb < ub) {
        mid = (lb + ub) / 2;

        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int max= 1000, min =0, size = 1000;
    int arr[size];
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (max+1);
    }


    mergesort(arr, 0, size - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}