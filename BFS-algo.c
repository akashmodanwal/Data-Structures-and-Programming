/**
*Title: Breadth First Search Traversal
*File : BFS-algo.cpp
*Author: Akash Modanwal
*date:   January 2021
*couse:  DSP Lab
*
*purpose of program:	
*		This program traverses a graph using BFS algorithm.
**/
#include<stdio.h>
#include<stdlib.h>
#define MAX 150
//initializing the variables
int n;
int matrix[MAX][MAX];
int visited[MAX];

int queue[MAX], front = -1,rear = -1;
void enqueue(int node);
int dequeue();
int isEmpty_queue();

//this function prints Breadth first search traversal

void BFS()
{
    int i,v=0;
	printf("Breadth First Search Traversal is given as :\n");
   for(i=0; i<n; i++)
      visited[i] = 0;
   enqueue(v);
   while(!isEmpty_queue())
   {

      v = dequeue( );
       if(visited[v])
           continue;

      printf("(%d)-->",v);
      visited[v] = 1;

      for(i=0; i<n; i++)
      {
         if(matrix[v][i] == 1 && visited[i] == 0)
         {
            enqueue(i);
         }
      }
   }
   printf("END\n");
}

// this function inserts a node from back of queue

void enqueue(int node)
{
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else
   {
      if(front == -1)
         front = 0;
      rear = rear+1;
      queue[rear] = node ;
   }
}

//checks if queue is empty

int isEmpty_queue()
{
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}

//this function deletes a node from rear of a queue

int dequeue()
{
   int delete_item;
   if(front == -1 || front > rear)
   {
      printf("Queue Underflow\n");
      exit(1);
   }

   delete_item = queue[front];
   front = front+1;
   return delete_item;
}

//driver function

int main()
{
 	printf("Program to find Breadth First Traversal of a given Graph\n");
   int count,e,start,end;
   printf("Enter number of Nodes : \n");
   scanf("%d",&n);
   printf("Enter number of Edges : \n");
   scanf("%d",&e);

   for(count=1; count<=e; count++)
   {
      printf("Enter Edge (%d) : ",count);
      scanf("%d %d",&start,&end);
         matrix[start][end] = 1;
         matrix[start][end] = 1;
   }
     BFS();

   
   return 0;
}
