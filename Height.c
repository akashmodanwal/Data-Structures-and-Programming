/**
*Title: Calculate height of BST
*File : height.cpp
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program takes no of nodes 
*               and nodes as input and builds a BST and prints height of the tree
*
**/
#include <stdio.h>
#include <stdlib.h>

//node initialization

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;

//creates new node

Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

// this function calculates height of the tree

int getHeight(Node* root){
 
    int height =0;
    if (root) {
        if (root->left || root->right) {
             int leftheight = 0, rightheight = 0;
            if (root->left) {
                leftheight = getHeight(root->left);
            }
            if (root->right) {
                rightheight = getHeight(root->right);
            }
            if (leftheight > rightheight) {
                height = leftheight + 1;
            } 
            else {
                height = rightheight + 1;
            }
        }
        else{ height = height + 1;
        }
    }
    return height;
}

// inserts node to tree

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
//Driver function
int main(){
    Node* root=NULL;
    int i,data;
    scanf("%d",&i);
    while(i>0){
        i--;
        scanf("%d",&data);
        root=insert(root,data);
    }
    int height=getHeight(root);
    printf("%d",height);
    return 0;
    
}