/* 
* Title : Program to Add, Delete, Display and Search elements in a 
*			Singly Linked List.And reverse the linked list
*File : linked_list_implement.c
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*			This program is implementation of linked list and it's operations like 
*			Add_node,Delete_node, Reverse linked list and search an element.
	
* References:
*			My Gate Preparation Notebook
**/


#include<stdio.h>
#include<stdlib.h>

//node structure

struct node
{
	int val;
	struct node *link;
};
struct node *head = NULL;

/*
* void add_node(int x)
*	summary:
*		This function creates new node and add it to beginning of linked list with value x.
*	Parameters:
*		int x : value that has to added to the linked list
*	Return value : None : Modifies the Linked list
*/


int add_node(int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=x;
	temp->link=head;
	head=temp;
	printf("%d added to the Beginning of the Linked List\n",x);

}

/*
* void display()
*	summary:
*		This function displayes entire linked list.
*	
*	Parameters: None
*
*	Return value : None 
*/

void display(){
	struct node *temp= head;
	printf("\nLinked List is given as :\n");
	while(temp!=NULL){
		printf("%d\n",temp->val);
		temp=temp->link;
		}
	}
	
	
/*
* void delete_node()
*	summary:
*		This function deletes a node from the beginning of the linked list.
*	Parameters: None
*
*	Return value : None 
*/


void delete_node(){
	struct node *temp =head;
	if(temp==NULL){
		printf("Linked List is Empty\n");
	}
	else{
		printf("\n%d got deleted from the Beginning of the Linked List\n",temp->val);
		head=head->link;
		free(temp);
		
	}
	}
	
/*
* void reverse_linked_list()
*	summary:
*		This function reverses the linked list
*	Parameters: None
*
*	Return value : None
*/

void reverse_linked_list(){
	struct node *prev, *current;
	if(head!=NULL){
		prev=head;
		current=head->link;
		head=head->link;
		prev->link=NULL;
		while(head!=NULL){
			head=head->link;
			current->link=prev;
			prev=current;
			current=head;
		}
	head=prev;
	printf("\nLinked List Reversed Succesfully\n");
	}
}

/*
* void search(int val)
*	summary:
*		This function searches val in entire linked list and returns index of the val.
*	
*	Parameters:
*		int val : element that has to be searched
*
*	Return value : int index : index of val
*/

int search(int val){
	int index;
	printf("\nSearching Node with value %d\n",val);
	struct node *current;
	index=0;
	current=head;
	while(current!=NULL && current->val !=val){
		index++;
		current=current->link;
		}
	return (current !=NULL)? index : -1;
	}
	
// Main Function
int main(){
	printf("Implementation of Linked List and It's operations such as Add_node , Delete_node, Display, Search and Reverse");
	printf("\n-------------------------------------------------------------------------------------------------------------\n");
	add_node(12);
	add_node(13);
	add_node(23);
	add_node(55);
	add_node(532);
	add_node(25);
	add_node(99);
	add_node(78);
	display();
	delete_node();
	delete_node();
	delete_node();
	display();
	reverse_linked_list();
	display();
	printf("\nNode with Value 23 Found at Index %d\n",search(23));
	return 0;

	}
