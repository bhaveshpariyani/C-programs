#include<stdio.h>
#include<math.h>
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    printf("\n");
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int median(int a[],int low,int high){
    int i,min,med,j,temp;
    int size=high-low+1;

    if(size%2==1)
        med=ceil((low+high)/2);
    else
        med=ceil((low+high)/2)+1;
    for(i=low;i<=med;i++)
    {
       min=i;
       for(j=i+1;j<=high;j++)
       {
           if(a[j]<a[min])
            min=j;
       }
       temp=a[i];
       a[i]=a[min];
       a[min]=temp;
    }

    return a[med];
}
int printindex(int a[],int x,int n)
{
    int i,position;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {position=i;break;}
    }

    return position;
}
int pseudomed(int a[],int low,int high){
    int n=high-low+1;
    int sizeofmed=ceil((float)n/5),x,mom;
    int med[sizeofmed],i;
    x=floor((float)n/5);
    int low_c,high_c;
    //calculate median of floor(n/5) arrays

    for(i=0;i<x;i++){
            low_c=(5*i)+low;
            high_c=(5*(i+1))+low-1;

        med[i]=median(a,low_c,high_c);
    }
    low_c=(5*i)+low;
    high_c=high;
    med[i]=median(a,low_c,high);
    mom=median(med,0,sizeofmed-1);

    return mom;
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high,int size)
{   static int phase=1;
    int pivot = pseudomed(arr,low,high) ;   // pivot

    int i = (low - 1),last_swap,j;  // Index of smaller element


    int pivot_index=printindex(arr,pivot,size);
    for (j = low; j <= high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] <= pivot && j!=pivot_index)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            last_swap=j;
        }
    }
   
    if(last_swap!=i)
        swap(&arr[i+1],&arr[last_swap]);

    return (i+1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high,int size)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high,size);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,size);
        quickSort(arr, pi + 1, high,size);
    }
}


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5,10,98,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    int size=n;
    quickSort(arr, 0, n-1,size);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
