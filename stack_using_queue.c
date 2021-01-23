/*
*Title: Implementation of Stack using Queue
*File :  stack_using_queue.c
*Author: Akash Modanwal
*date:   November 2020
*couse:  DSP Lab
*
*purpose of program:	
*			This program is implementation of Stack using Queue. It performs Push operation by using two queues.
*			enqueue and dequeue is used for push and pop operation for implementation of Stack.
**/

#include<stdio.h>
#include<stdlib.h>

// defining a node
struct node
{
    int data;
    struct node * next;
};

// defining a queue

struct queue
{
    struct node *rear;
    struct node *front;
};

//initialization of functions

void initial(struct queue *);
void enqueue(struct queue *,int);
int dequeue(struct queue *);
void display(struct queue *);
void push(int);
void pop();

struct queue queue1,queue2; //initializing two queues for stack

//intialize the queue

void initial(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

  /* void enqueue( queue* q, int n) 
  * 
  * Summary of the enqueue function: 
  * 
  *    This function puts given variable x into queue.
  * 
  * Parameters  : int  : x : value that is going in the queue
  *				 queue * :q : queue in which enqueue operation is happening.
  * 
  * Return Value : Nothing -- Note: Modifies the queue
  */ 
  
void enqueue(struct queue *q,int n)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
   
    tmp->data=n;
    tmp->next=NULL;

    if(q->front==NULL)
    {
        q->rear=tmp;
        q->front=tmp;
        return;
    }

    q->rear->next=tmp;
    q->rear=tmp;
}

  /* void dequeue( queue* q) 
  * 
  * Summary of the dequeue function: 
  * 
  *    This function removes a element from front of queue.
  * 
  * Parameters  : 
  *				 queue * :q : queue in which enqueue operation is happening.
  * 
  * Return Value : int x : elememnt that got deleted from queue.
  */ 
  

int dequeue(struct queue *q)
{
    struct node *tmp;
    int x;
    if(q->front==NULL)
    {
        printf("\nqueue is empty");
        return NULL;
    }

    //itm=q->front->data;
    tmp=q->front;
    x=tmp->data;
    q->front=tmp->next;
    free(tmp);
    return x;

}


/* void display( queue* q) 
  * 
  * Summary of the dequeue function: 
  * 
  *    This function prints entire stack.
  * 
  * Parameters  : 
  *				 queue * :q : queue that has to be displayed.
  * 
  * Return Value : None
  */ 
  
void display(struct queue *q)
{
    struct node *tmp;
    tmp=q->front;
    printf("\nDisplaying Stack\n");
    while((tmp)!=NULL)
    {
        printf("%d\n",(tmp->data));   
        tmp=tmp->next;
    }
    printf("\n");
}

 /** 
  * void push( int x ) 
  * 
  * Summary of the push function: 
  * 
  *    This function pushes the gieven integer into the stack by using enqueue and dequeue 
  *		operations on two queues.
  * 
  * Parameters   :  x : int  : this intrger gets pushed in the stack
  * 
  * Return Value : Nothing -- Note: Modifies the stack 
  */ 

void push(int x)
{
    struct queue tmp;
    int j;
    enqueue(&queue2,x);
   
    while(((&queue1)->front)!=NULL)
    {
        j=dequeue(&queue1);
        enqueue(&queue2,j);
    }

   
    tmp=queue1;  //swap queue1 and queue2
    queue1=queue2;
    queue2=tmp;

    printf("\n%d got pushed in the Stack\n",x);

}
	/* 
  * void pop( ) 
  * 
  * Summary of the pop function: 
  * 			pop function deletes the top of the stack by dequeuing 
  *				the first queue.
  * 
  * Parameters   : None
  * 
  * Return Value : None
  */ 
void pop()
{
    printf("\n%d got popped from the stack\n",dequeue(&queue1));
}  

//main function
 
int main()
{

	printf("Implememting Stack using Queue\n");
	printf("---------------------------------\n");
    initial(&queue1);
    initial(&queue2);
    push(5);
    push(6);
    push(7);
    push(35);
    push(77);
    push(99);
    display(&queue1);
    pop();
    pop();
    display(&queue1);
   
    return 0;
}
//end of program
