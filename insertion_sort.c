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
void insertion_sort(int a[],int n){
	int i,j,val;
	for(i=1;i<n;i++){
		val=a[i];
		j=i-1;
		while(j>=0 && a[j]>val){
			a[j+1]=a[j];
			j--;		
		}
		a[j+1]=val;	
	}
}

int main(){
	int a[COUNT];
	sorted_array(a,COUNT);
	insertion_sort(a,COUNT);
	return 0;	
}