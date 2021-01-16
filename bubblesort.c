#include<stdio.h>
int main(){
    int n,i,j,temp,A[50];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d ",&A[i]);
    }
    //Logic for bubble sort
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(A[i]>A[j]){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    
}