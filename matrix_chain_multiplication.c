
#include <stdio.h>
#include<limits.h>
int s[5][5] = {0};
 void print_optimal(int i,int j)
{
if (i == j)
printf("A%d",i);
else
   {
      printf("(");
      print_optimal(i, s[i][j]);
      print_optimal(s[i][j] + 1, j);
      printf(")");
   }
}
void main(){
    int n = 5;
    int p[] = {5,4,6,2,7};
    int m[5][5] = {0};
    

    int j , min , q;

    for(int d = 1; d<n-1 ; d++){
        for(int i = 1; i<n-d ; i++){
            j = i+d;
            min = INT_MAX;
            for(int k = i; k<=j-1;k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if( q<min ){
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    printf("\nminimum cost == %d" , m[1][n-1]);
    printf("\noptimal paranthesis = ");
    int i = 1 ; j = n-1;
    print_optimal(i,j);
}
