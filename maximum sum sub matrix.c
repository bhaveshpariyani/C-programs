#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#include <stdbool.h>
#define N 5 

void matrix(int matrix[][N], int k) 
{ 
    if (k > N) return; 

    int Sum_matrix[N][N]; 

    for (int j=0; j<N; j++) 
    { 
        int sum = 0; 
        for (int i=0; i<k; i++) 
            sum += matrix[i][j]; 
        Sum_matrix[0][j] = sum; 

        for (int i=1; i<N-k+1; i++) 
        { 
            sum += (matrix[i+k-1][j] - matrix[i-1][j]); 
            Sum_matrix[i][j] = sum; 
        } 
    } 
  

    int max_sum = INT_MIN, *pos = NULL; 

    for (int i=0; i<N-k+1; i++) 
    { 

        int sum = 0; 
        for (int j = 0; j<k; j++) 
            sum += Sum_matrix[i][j]; 
 
        if (sum > max_sum) 
        { 
            max_sum = sum; 
            pos = &(matrix[i][0]); 
        } 

        for (int j=1; j<N-k+1; j++) 
        { 
            sum += (Sum_matrix[i][j+k-1] - Sum_matrix[i][j-1]); 

            if (sum > max_sum) 
            { 
                max_sum = sum; 
                pos = &(matrix[i][j]); 
            } 
        } 
    } 

    for (int i=0; i<k; i++) 
    { 
        for (int j=0; j<k; j++) 
            printf("%d ",*(pos + i*N + j));
        	printf("\n"); 
    } 
}

int main() 
{ 
    int matrix[N][N] = {{1, 1, 1, 1, 1}, 
        {2, 2, 2, 2, 2}, 
        {3, 8, 6, 7, 3}, 
        {4, 4, 4, 4, 4}, 
        {5, 5, 5, 5, 5}, 
    }; 
    int k = 3; 
   
    printf("Maximum sum 3 x 3 matrix is\n"); 
    matrix(matrix, k); 
  
    return 0; 
} 