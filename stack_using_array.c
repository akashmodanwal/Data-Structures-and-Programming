/**
*Title: Implementation of Stack using Array
*File :  stack_using_array.cpp
*Author: Akash Modanwal
*date:   November 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program is implementation of stack using Array. It performs pop and push operations.
*				it stores all the data in Array.
* References:
*			Stack data structure (Introduction and program). (2019, July 19). 
*			GeeksforGeeks. https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
**/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Declaration of vaiables and functions

int stack[MAX],TOP;
void display(int []);
void push(int [],int);
int pop (int []);
 
 /** 
  * void display( int *) 
  * 
  * Summary of the display function: 
  *					it prints the the stack.
  * 
  * Parameters   : Array
  * 
  * Return Value : None 
  */ 
void display(int stack[])
{
	
    int i=0;
    printf("\nDisplaying Entire Stack\n");
	if(TOP==-1)
    {
        printf("Stack is Empty .\n");
        return;
    }
 
    for(i=TOP;i >0;i--)
    {
        printf("\n%d",stack[i]);
    }
    printf("\n\n");
    
}

/** 
  * void push( int * STACK,int value ) 
  * 
  * Summary of the push function: 
  * 
  *    This function pushes the gieven integer into the stack.
  * 
  * Parameters   :  STACK: array , value : int  
  * 
  * Return Value : Nothing -- Note: Modifies the stack 
  */ 
  
void push(int stack[],int item)
{
    if(TOP==MAX-1)
    {
        printf("\nstack is FULL CAN't ADD ITEM\n");
        return;
    }
    TOP++;
    stack[TOP]=item;
    printf("Pushed %d into the Stack\n",item);
}

/** 
  * int pop( int*  ) 
  * 
  * Summary of the pop function: 
  * 			pop function deletes the top of the stack and prints it.
  * 
  * Parameters   : STACK : arraay
  * 
  * Return Value : deletedItem :int 
  */ 
  
 int pop(int stack[])
{
    int value;
    if(TOP==-1)
    {
        printf("stack is EMPTY.\n");
        return 0;
    }
 
    value=stack[TOP];
    TOP--;
    printf("%d deleted successfully\n",value);
    return value;
}
// main function

    int main(){
    	printf("Implementation of STACK using ARRAY\n");
    	printf("-------------------------------------\n");
    	push(stack,3);
		push(stack,6);
		push(stack,43);
		push(stack,32);
		push(stack,45);
		display(stack);
		pop(stack);
		pop(stack);
		pop(stack);
		display(stack);
	}
