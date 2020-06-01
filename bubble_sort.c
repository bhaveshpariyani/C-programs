#include<stdio.h>
#include<stdlib.h>
#include <time.h>
# include <sys/time.h>
#define COUNT 100

void printarray(int a[],int n){
	int i=0;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void swap(int *a,int *b){
	int temp=*a;
	
	*a=*b;
	*b=temp;
	
}
void sorted_array(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		a[i]=i;
}
void reverse_array(int a[],int n){
	int i,j=n;
	for(i=0;i<n;i++)
		{a[i]=j--;}
}

void random_array(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		a[i]=rand();
}
void bubble_sort(int a[],int n){
	int i,j,swapped;
	for(i=0;i<n-1;i++){
		swapped=0;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
				{swap(&a[j],&a[j+1]);swapped=1;}		
		}
		if(swapped==0)
			break;	
	}
	//printarray(a,n);
}
int main(){
	int a[COUNT];
	sorted_array(a,COUNT);
	bubble_sort(a,COUNT);
	return 0;	
}
