/**
*Title: Implementation of Queue using Stack
*File :  queue_using_stack.cpp
*Author: Akash Modanwal
*date:   November 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program is implementation of queue using stack. I
*			
* References:
*			
*			C program to implement queues using stacks. (2017, August 16). 
*			Sanfoundry. https://www.sanfoundry.com/c-program-implement-queues-using-stacks/
**/
#include<stdio.h>
#include<stdlib.h>
# define N 20 //defining the size of queue
int s[N],top = -1;

	/* 
  * int pop( ) 
  * 
  * Summary of the pop function: 
  * 			pop function deletes the top of the stack .
  * 
  * Parameters   : None
  * 
  * Return Value : int : popped item
  */ 
  
int pop()//function to remove an element from stack
{
	return s[top--];
}

 /** 
  * void push( int x ) 
  * 
  * Summary of the push function: 
  * 
  *    This function pushes the given integer
  
  * Parameters   :  x : int  : this intrger gets pushed in the stack
  * 
  * Return Value : Nothing -- Note: Modifies the stack 
  */ 

void push(int x)//function to insert an element into stack
{
	if(top == N-1)
		printf("Stack is Full");
	else
	{
		top++;
		s[top] = x;	
	}
}

/* void enqueue(  int n) 
  * 
  * Summary of the enqueue function: 
  * 
  *    This function puts given variable x into queue.
  * 
  * Parameters  : int  : x : value that is going in the queue
  * 
  * Return Value : Nothing -- Note: Modifies the queue
  */
  
void enqueue(int x)//function to insert element in the queue using recursive stack call
{
	push(x);
	printf("%d added to end of the Queue\n",x);
}

/* void display( ) 
  * 
  * Summary of the dequeue function: 
  * 
  *    This function prints entire queue.
  * 
  * Parameters  : None	 
  * Return Value : None
  */ 

void display()//function to print elements of a queue
{
	int i;
	printf("\nDisplaying the Queue:\n");
	for(i=0;i<=top;i++)
		printf("%d\n",s[i]);
}

/* int dequeue( ) 
  * 
  * Summary of the dequeue function: 
  * 
  *    This function removes a element from front of queue.
  * 
  * Parameters  : None
  * 
  * Return Value : int res : elememnt that got deleted from queue.
  */ 
  
int dequeue()//function to dequeue element from a queue using recursive stack call
{	
	int data,res;
	if(top == -1)
		printf("Queue is Empty");
	else if(top == 0){
		return pop();
		}
	data = pop();
	res = dequeue();
	push(data);
	return res;
 	
}
//main function
int main()
{
	
	printf("Implementation of Queue using Stack\n");
	printf("-------------------------------------\n");
	enqueue(12);
	enqueue(4);
	enqueue(32);
	enqueue(122);
	enqueue(99);
	display();
	
	printf("\n%d got removed form the front of Queue\n",dequeue());
	printf("%d got removed form the front of Queue\n",dequeue());
	printf("%d got removed form the front of Queue\n",dequeue());
	display();
	return 0;
}

