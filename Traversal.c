/**
*Title: Traversal of Binary Tree
*File : traversal.cpp
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program takes no of nodes and nodes as input 
*				and builds a Binary tree and outputs Prorder ,Inorder 
*				and Postorder travesal of the tree. 
*
**/
#include <stdio.h>
#include <stdlib.h>

// definition of node

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree_node;

//this function inserts a node to the tree

tree_node *insert_node(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
        {
            root->right = insert_node(root->right, value);
        }
        if (value < root->data)
        {
            root->left = insert_node(root->left, value);
        }
    }
    return root;
}

 // This function prints Preorder of the Tree
 
void preorder(tree_node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// This function prints Inorder of the tree

void inorder(tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// This function Postorder of the tree

void postorder(tree_node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

//Driver Function

int main()
{
    tree_node *root = NULL;
    int n;
    int node;
    scanf("%d", &n);
    int i;
    for (i= 0; i < n; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }

    preorder(root);
    printf("\n");
 
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
