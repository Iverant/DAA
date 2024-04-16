#include<stdio.h>
#include<limits.h>
#include<time.h>

#define ROWS 4
#define COLS 4

int matrix[ROWS][COLS] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int assignment() {
    int minSum = INT_MAX;
    int sum;
    int i, j, k, l;
    clock_t start,end;

    start=clock();
   
    // Generate all possible combinations of one element from each column
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < ROWS; j++) {
            for(k = 0; k < ROWS; k++) {
                for(l = 0; l < ROWS; l++) {
                    // Ensure each row is selected exactly once
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        // Calculate the sum of the current combination
                        sum = matrix[i][0] + matrix[j][1] + matrix[k][2] + matrix[l][3];

                        // If the sum is less than minSum, update minSum
                        if(sum < minSum) {
                            minSum = sum;
                        }
                    }
                }
            }
        }
    }
    end=clock();

    double timeConsumed= ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime consumed : %f",timeConsumed);

    return minSum;
}

void main() {
    int minSum = assignment();
    printf("Minimum sum of one element from each column: %d\n", minSum);

}