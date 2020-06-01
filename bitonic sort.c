#include<stdio.h>
void printarray(int a[],int n){
	int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void compare(int a[],int start,int end,int dir){
	int size = (end-start+1),i,count,temp,k;
	if (size==1)
		return;
	else{
		k=size/2;
	for(i=start,count=0;count<k;i++){

		if(dir==(a[i]>a[i+k])){
			temp=a[i];                  //swap
			a[i]=a[i+k];
			a[i+k]=temp;
		}
		count++;
	}

	
		compare(a,start,end-k,dir);
		compare(a,start+k,end,dir);
	}
}


void divide(int a[],int start,int end,int dir){
	int size = end-start+1;
	if(size<=1)
		return;

		int k=size/2;

		divide(a,start,end-k,1);
		divide(a,start+k,end,0);

		compare(a,start,end,dir);


}



void main(){
	int a[]={3,7,4,8,6,2,1,5};
	printarray(a,8);
	divide(a,0,7,1);
	printarray(a,8);
	printf("\n");

}
