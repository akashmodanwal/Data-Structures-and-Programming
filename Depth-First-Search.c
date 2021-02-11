/**
*Title: Depth First Search Traversal
*File : DFS-algo.cpp
*Author: Akash Modanwal
*date:   January 2021
*couse:  DSP Lab
*
*purpose of program:	
*		This program traverses a graph using DFS algorithm.
**/
#include <stdio.h>
#define MAX 20

// initialize variables

int stack[MAX];
int top=-1;
int visited[MAX];
int n;
int matrix[MAX][MAX];

//pushes a node into stack

void push(int val){
    stack[++top]=val;
}
//pops a node from the stack
int pop(){
    int x=stack[top--];
    printf("%d-->",x);
    return x;
}

//checks ifstack is empty

int stackempty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void dfs(int source){
    push(source);
    visited[source]=1;
    while(!stackempty()){
        int i;
        int v=pop();
        for(i=n-1;i>=0;i--){
            if(matrix[v][i]&&!(visited[i])){
                push(i);
                visited[i]=1;
            }
        }
    }
    printf("END\n");
}
//driver function
int main() {

printf("Program to find Depth First Traversal of a given Graph\n");
 int e,i;
 printf("Enter the Number of nodes and edges:");
 scanf("%d %d",&n,&e);
 int c,b;
 for(c=0;c<n;c++) for(b=0;b<n;b++) matrix[c][b]=0;
 for(c=0;c<n;c++) visited[c] = 0;
 for(i=0;i<e;i++)
 {

     int start,end;
     printf("Enter Edge ");
    scanf("%d %d",&start,&end);
     matrix[start][end] = 1;
     matrix[end][start] = 1;
 }
 printf("\nDepth First Search Traversal is given as :\n");
 dfs(0);
 printf("\n");
 
 return 0;
}
