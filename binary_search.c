#include <stdio.h> 
#include <limits.h>

//to get sum of frequency from i to j
int sum(int freq[], int i, int j) 
{ 
    int sum = 0; 
    for (int k = i; k <=j; k++) 
       sum += freq[k]; 
    return sum; 
}

int function(int keys[], int freq[], int n){
  int cost[n][n] , i,j;
    for (i = 0; i < n; ++i)
     {
       for (j = 0; j < n; ++j)
       {
         cost[i][j] = 0;
       }
     }

     //assigning diagonal elements
     for (i = 0; i < n; i++) 
        cost[i][i] = freq[i]; 


      for(int d = 2; d <= n ; d++){

        for (i = 0; i <= n-d+1; ++i)
        {
          j = i+d-1;
          cost[i][j] = INT_MAX;
          for (int r = i; r <=j ; ++r)
          {
            int temp = sum(freq,i,j);

            if (r > i)
            {
              temp += cost[i][r-1];
            }
            if (r < j)
            {
              temp += cost[r+1][j];
            }

            if (temp < cost[i][j])
            {
              cost[i][j] = temp;
            }
          }
        }
      }

      printf("cost == %d\n", cost[0][n-1]);
}

int main(int argc, char const *argv[])
{
  int keys[] = {10, 20, 30,40,50,60}; 
  int freq[] = {3,6,1,8,5,4}; 
  int n = sizeof(keys)/sizeof(keys[0]);
  function(keys, freq, n); 
  return 0;
}