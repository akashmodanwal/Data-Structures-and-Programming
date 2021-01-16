/**
*Title: Implementation of Queue using Array
*File :  queue_using_array.cpp
*Author: Akash Modanwal
*date:   November 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program is implementation of Queue using Array. It performs enqueue and dequeue operations.
*				it stores all the data in Array.
* References:
*			https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
**/

#include <stdio.h>
#include <stdlib.h>

// a node of queue
typedef struct queue {
  int head;
  int tail;
  int size;
  int Q[];
}queue;
//creats a queue
queue* new_queue(int size) {
  queue *q = (struct queue*) malloc(sizeof(queue) + size*sizeof(int));

  q->head = 1;
  q->tail = 1;
  q->size = size;

  return q;
}
//checks if queue is empty
int is_empty(queue *q) {
  if(q->tail == q->head)
    return 1;
  return 0;
}
// checks if queue is full
int is_full(queue *q) {
  if(q->head == q->tail+1)
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

void enqueue(queue *q, int x) {
  if(is_full(q)) {
    printf("Queue Overflow\n");
  }
  else {
    q->Q[q->tail] = x;
    if(q->tail == q->size)
      q->tail = 1;
    else
      q->tail = q->tail+1;
  }
  printf("\n%d adde to the Queue\n",x);
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
  if(is_empty(q)) {
    printf("Underflow\n");
    return -1000;
  }
  else {
    int x = q->Q[q->head];
    if(q->head == q->size) {
      q->head = 1;
    }
    else {
      q->head = q->head+1;
    }
    printf("\nRemoved %d from the Queue\n",x);
    return x;
  }
  
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
  int i;
  for(i=q->head; i<q->tail; i++) {
    printf("%d\n",q->Q[i]);
    if(i == q->size) {
      i = 0;
    }
  }
}

//main function 

int main() {
	printf("Queue using Arrys\n");
	printf("----------------------------\n");
  queue *q = new_queue(10);
  enqueue(q, 21);
  enqueue(q, 40);
  enqueue(q, 34);
  enqueue(q, 99);
  enqueue(q, 323);
  printf("Queue :\n");
  display(q);

  printf("\n");

  dequeue(q);
  dequeue(q);
  display(q);

  printf("\n");

  enqueue(q, 603);
  enqueue(q, 70);
  printf("Queue :\n");
  display(q);
  return 0;
}

