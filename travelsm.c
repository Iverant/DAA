#include <stdio.h>

int s, c[100][100], ver;
int optimum = 999, sum;

void swap(int v[], int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void travelling(int v[], int n, int i){
    int j,sum1,k;
    if (i == n){
        if (v[0] == s){
            for (j = 0; j < n; j++)
                printf("%d ", v[j]);
            sum1 = 0;
            for (k = 0; k < n - 1; k++){
                sum1 = sum1 + c[v[k]][v[k + 1]];
            }
            sum1 = sum1 + c[v[n - 1]][s];
            printf("sum = %d\n", sum1);
            if (sum1 < optimum)
                optimum = sum1;
        }
    }else{
        for (j = i; j < n; j++){
            swap(v, i, j);
            travelling(v, n, i + 1);
            swap(v, i, j);
        }
    }
} 

void main(){
    int ver, v[100], i, j;
    printf("\nEnter number of cities : ");
    scanf("%d", &ver);
    for (i = 0; i < ver; i++)
        v[i] = i + 1;
    for (i = 1; i <= ver; i++){
        for (j = 1; j <= i; j++){
             int num = rand() % 10;
             c[i][j] = c[j][i] = num;
        }
    }
    for (i = 1; i <= ver; i++){
        for (j = 1; j <= ver; j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter source : ");
    scanf("%d", &s);
    travelling(v, ver, 0);
    printf("\nOptimum solution with brute force technique is=%d\n", optimum);
}