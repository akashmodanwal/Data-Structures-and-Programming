/**
*Title: Find Preorder by using Postorder and Inorder
*File :  preorder.c
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program Findes Preorder by using postorder and inorder.
*
**/
#include <stdio.h>
#include <stdlib.h>
 
// binary tree with left and right child
struct Node {
	int data;
	struct Node *left, *right;
};

// create a new node
struct Node* newNode(int data);

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
 
 // function  to build binary tree
 
struct Node* buildUtil(int in[], int post[], int inStrt,
				int inEnd, int* pIndex)
{
	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Postorder traversal using
	postIndex and decrement postIndex */
	struct Node* node = newNode(post[*pIndex]);
	(*pIndex)--;

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return node;

	/* Else find the index of this node in Inorder
	traversal */
	int iIndex = search(in, inStrt, inEnd, node->data);

	/* Using index in Inorder traversal, construct left and
	right subtress */
	node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
	node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

	return node;
}

struct Node* buildTree(int in[], int post[], int n)
{
	int pIndex = n - 1;
	return buildUtil(in, post, 0, n - 1, &pIndex);
}


int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			break;
	}
	return i;
}

/* allocates a new node */
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  
	//struct Node* Node = (struct Node *)malloc(sizeof(struct Node) );
    //struct node* Node = (struct Node *) malloc( sizeof(struct Node) );
 
	node->data = data;
	node->left = node->right = NULL;
	return (node);  
}


void preOrder(struct Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Main function
int main()
{
    int n,i;
	int in[50],post[50];
	
   scanf("%d",&n);
 
   for(i=0;i<n;i++)
      scanf("%d",&in[i]);
 
   for(i=0;i<n;i++)
      scanf("%d",&post[i]);
      
	struct Node* root = buildTree(in, post, n);
	preOrder(root);

	return 0;
}
