/*
*Title: Implementation of Queue using linked list
*File :  queue_using_linkedlist.cpp
*Author: Akash Modanwal
*date:   November 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program is implementation of Queue using Linked List. It performs enqueue and dequeue operations.
*				it stores all the data in Linked List.
* References:
*			Queue - Linked list implementation - GeeksforGeeks. (2020, September 28). 
*			GeeksforGeeks. https://www.geeksforgeeks.org/queue-linked-list-implementation/?ref=lbp
**/

#include <stdio.h>
#include <stdlib.h>
//define structure
typedef struct node {
  int data;
  struct node *next;
}node;
//define linked list
typedef struct linked_list {
  struct node *head;
  struct node *tail;
}queue;

//to make new node
node* new_node(int data) {
  node *z;
  z = (struct node*)malloc(sizeof(struct node));
  z->data = data;
  z->next = NULL;

  return z;
}

//to make a new queue
queue* new_queue() {
  queue *q =(struct linked_list*) malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;

  return q;
}

/* void display( queue* q) 
  * 
  * Summary of the dequeue function: 
  * 
  *    This function prints entire queue.
  * 
  * Parameters  : 
  *				 queue * :q : queue that has to be displayed.
  * 
  * Return Value : None
  */ 
  
void display(queue *q) {
  node *temp = q->head; //temporary pointer to point to head

  while(temp != NULL) { //iterating over queue
    printf("%d\t", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

// checks if queue is empty

int is_empty(queue *q) {
  if(q->head == NULL)
    return 1;
  return 0;
}
/** 
  * void enqueue( queue* q, int x) 
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

void enqueue(queue *q, node *n) {
  if(is_empty(q)) {
    q->head = n;
    q->tail = n;
  }
  else {
    q->tail->next = n;
    q->tail = n;
  }
}

/** 
  * void dequeue( queue* q) 
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
  
int dequeue(queue *q) {
  if(is_empty(q)) {       //underflow condition
    printf("Underflow\n");
    return -1000;
  }
  else {
    int x = q->head->data;
    node *temp = q->head;
    q->head = q->head->next;
    free(temp);
    printf("%d Removed from the Queue\n",x);
    return x;
  }
}

//main fuction

int main() {
	printf("QUEUE USING LINKED-LIST\n");
	printf("-------------------------\n");
  queue *q = new_queue();

  node *a, *b, *c, *d;
  a = new_node(20);
  b = new_node(30);
  c = new_node(60);
  d = new_node(12);
 
  dequeue(q);
  enqueue(q, a);
  enqueue(q, b);
  enqueue(q, c);
 
  printf("Queue:\n");
  display(q);
  dequeue(q);
  dequeue(q);
  enqueue(q, d);
  printf("Queue:\n");
  display(q);


  return 0;
}
