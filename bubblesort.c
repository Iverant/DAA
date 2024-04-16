#include<stdio.h>

int arr[] = {4, 6, 2, 7, 5, 9, 1, 8};
int n = 8;

int i, j;
int temp;

int main(){

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<= n-2-i; j++){

            if(arr[j+1]<arr[j]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i<n; i++){
        printf("%d", arr[i]);
    }



}


