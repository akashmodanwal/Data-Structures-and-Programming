/**
*Title: Implementation of Stack using Linked list
*File :  stack_using_linkedlist.cpp
*Author: Akash Modanwal
*date:   November 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program is implementation of stack using linked list. It performs pop and push operations.
*				it stores all the data in linked list.
* References:
*			Stack data structure (Introduction and program). (2019, July 19). 
*			GeeksforGeeks. https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
**/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//define node

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *top;
   
 /** 
  * void push( int value ) 
  * 
  * Summary of the push function: 
  * 
  *    This function pushes the gieven integer into the stack.
  * 
  * Parameters   :  value : int  : this intrger gets pushed in the stack
  * 
  * Return Value : Nothing -- Note: Modifies the stack 
  */ 

void push(int value)
{
    node *tmp;
    tmp = (struct node*)malloc(sizeof(node)); //dynamically created node
    tmp -> data = value;
    tmp -> next = top;
    top = tmp;
    printf("Pushing %d into stack\n",value);
}
             
 /** 
  * int pop(  ) 
  * 
  * Summary of the pop function: 
  * 			pop function deletes the top of the stack and prints it.
  * 
  * Parameters   : None
  * 
  * Return Value : value that is deleted from the top of the strack 
  */ 
int pop()
{
    node *tmp;
    int n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    printf("Popped %d out of stack\n",n);
    free(tmp);// free the memory
    
    return n;
}
             
 /** 
  * void display( node * head) 
  * 
  * Summary of the display function: 
  *					it prints the the stack.
  * 
  * Parameters   : node *head :top of the stack
  * 
  * Return Value : None 
  */ 
void display(node *head)
{
    if(head == NULL)// if stack is empty
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }

}

//main function


int main()
{
    printf("Stack using Linked-List\n");
    top=NULL;
    push(10);
    push(93);
    push(330);
    push(40);
	push(35);
	push(123);
	printf("Displaying stack elments\n");
	display(top);
	pop();
	pop();
    pop();
    printf("Displaying stack elements\n");
    display(top);
    return 0;
}
//end of program
