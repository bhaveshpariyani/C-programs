#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//merge sort for sorting separate files internally
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    
    int L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  
       
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

//function to write into file from array
void write_file(const char* file_name,int a[],int size)
{
	FILE* fp=fopen(file_name,"w");
	int i;
	if(!fp)
		printf("\nerror\n");
	for(i=0;i<size;i++)
		fprintf(fp,"%d ",a[i]);
	fclose(fp);
}


//get index of minimum element from given array
int getmin(int a[],int size)
{
	int min=0,i;
	//printArray(a,size);										
	for(i=1;i<size;i++){
		
		if(a[i]<a[min])
			min=i;
		
	}
	return min;
}

//merge all individual files in the file named "output"
void merge_files(int count,int size)
{
	FILE* op=fopen("output","w");
	int a[count];				//array a is used for k-way sorting
	int min,j=0;
	FILE* fp[count];
	char file_name[2];

	for(j=0;j<count;j++)
		{sprintf(file_name, "%d", j);
		fp[j]=fopen(file_name,"r");
		if(!fp[j])
		break;
		}
	for(j=0;j<count;j++)
			fscanf(fp[j],"%d ",&a[j]);
	
	j=0;
	while(j!=count){
		
		
		min=getmin(a,count);
		fprintf(op,"%d ",a[min]);
																																																																																																																																																																																																																																																																																																																																																

		if(fscanf(fp[min],"%d ",&a[min])!=1){
			a[min]=INT_MAX;			//assign maximum to index which file is ended
			j++;		
		}
		
				
	}	
	fclose(op);
	for(j=0;j<count;j++)
		fclose(fp[j]);
	
}
void create_small_files(int count, int size,const char* input){
	int i,j,x;
	FILE* fp[count];
	char file_name[2];
	FILE* in=fopen("input","r");
	for(i=0;i<count;i++){
		sprintf(file_name, "%d", i);
		fp[i]=fopen(file_name,"r");
		
		for(j=0;j<size;j++){
				fscanf(in,"%d ",&x);
				fprintf(fp[i],"%d ",x);
			}
		
		}
}
//create input file
void createfiles(int count,int size)
{

	int i;
	FILE* in=fopen("input","w");
	for(i=0; i<count*size;i++){
		fprintf(in,"%d ",rand());
	}

	create_small_files(count, size, "input");
}

void sort(int count,int size){
	createfiles(count,size);
	merge_files(count,size);
}

void main(){
	sort(10,10);
}
