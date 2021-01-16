/*
*Title: Sorting an Array and find first and last occurrences of a given element.
*File : sort_find.cpp
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program takes an array as input and sorts it in ascending order then it takes an element and 
*				finds it's first and last occurrences.
* References:
*			None
**/

#include<stdio.h>
/*
* void sort(int A[],int n)
*	summary:
*		This function sorts the elements in the array in ascending order using Bubble sort.
*	Parameters:
*		int A[] : array that has to be sorted
*		int n   : size of the array
*
*	Return value : None : Modifies the Array A[]
*/

void sort(int A[] , int n ){
	int i,j,temp;
	for(i=0;i<n;i++){
		
		for(j=i+1;j<n;j++){
			
			if(A[i]>=A[j]){  //sorting
				
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}			
		}
	}
	printf("\nArray Sorted Succesfully\n");
}
/*
* void search(int A[],int n,int element)
*	summary:
*		This function searches for the first and last occurrences of given element in the Array.
*	Parameters:
*		int A[] : array that has to be sorted
*		int n   : size of the array
*		int element : element that's position has to be found
*
*	Return value : None : Prints position of occurrences
*/

void search(int A[],int n,int element){
	int first=0,last=0,i;
	printf("\nSearching...\n");
	for(i=0;i<n;i++){
		if(element!=A[i]){     
			continue;
		}
		if(first==-0){    //first occurence stored 
			first=i;
		}
		last=i;          //last index of the element
		
	}
	printf("\nValue : %d\nFirst Occurrence : %d\nLast Occurrence : %d",element,first,last);
}

//Main Function

int main(){
	int A[20],n,i,element;
	printf("Sorting an Array and find first and last occurrence of given element\n");
	printf("-----------------------------------------------------------------------\n");
	
	//Input
	
	printf("Enter no of elements in the Array\n");
	scanf("%d",&n);
	printf("Enter elements of the Array\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		}

	//Output
	
	printf("\nUnsorted Array : \n");
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	sort(A,n);
	printf("\nSorted Array :\n");
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	printf("\n\nEnter the element for which you want to find Starting and Ending Position : ");
	scanf("%d",&element);
	search(A,n,element);
	
}
//end of program
