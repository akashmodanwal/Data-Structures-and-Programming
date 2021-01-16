#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include<math.h>

#define MAX_LIMIT 50 
 

// Tree Structure 
struct node 
{ 
	int data; 
	char symbol;
	char s[1];
	int isValue;
	struct node *left, *right; 
};//* nptr; 

// Function to create new node 
struct node* newNode(int value, char symbol, int isValue) 
{  

    struct node* n = (struct node *) malloc( sizeof(struct node) );
    
    if(isValue == 1)
	{
		n->data = value;
		n->symbol = symbol;	
		n->s[0] = symbol;	
	}
    else
	{
		n->symbol = symbol; 
		n->s[0] = symbol;	
	}
	n->isValue = isValue;
	n->left = n->right = NULL; 
	return n; 
} 

int isoperand(char s)
{
	if(s == '+' || s == '-' || 
	   s == '*' || s == '/' || 
	   //s == '(' || 
	   s == '^' ||
	   s == ')' )
	   return 0;
	else
		return 1;
}

int getPriority(char c)
{
    switch(c)
    {
	    case '(':
	        return 0;
	    case ')':
	        return 0;
	    case '+':
	        return 1;
	    case '-':
	        return 1;
	    case '*':
	        return 2;
	    case '/':
	        return 2; 
	    case '^':
	        return 3;
    } 
}

int isValidChar(char s)
{
	if(s == '+' || s == '-' || 
	   s == '*' || s == '/' || 
	   s == '^' || s == '(' || 
	   s == '0' || s == '1' || 
	   s == '2' || s == '3' || 
	   s == '4' || s == '5' || 
	   s == '6' || s == '7' || 
	   s == '8' || s == '9' ||  	   
	   s == ')' )
	   return 1;
	else
		return 0;
}


// Function to build Expression Tree   
struct node* build(char s[],int n) 
{ 

	// Stack to hold nodes 
	struct node* stN[50]; 

	// Stack to hold chars 
	char stC[50]; 
	//struct node* t,t1, t2; 
    struct node* t = (struct node *) malloc( sizeof(struct node) );
    struct node* t1 = (struct node *) malloc( sizeof(struct node) );
    struct node* t2 = (struct node *) malloc( sizeof(struct node) );
     
    int i;
    int value, isLastDigit = 0;
    int stC_top = -1,stN_top = -1;
    
    
	for (i = 0; i < n; i++) 
	{ 
		if (s[i] == '(') { 
			isLastDigit = 0;
			// Push '(' in char stack  
			stC_top++;
			stC[stC_top] = s[i];
		} 

		// Push the operands in node stack 
		else if (isoperand(s[i])) 
		{   
			value = s[i] - '0';
			
			//If the last char in the string is also digit means it is multi digit operand
			if(isLastDigit == 1) 
			{
				stN[stN_top]->data = stN[stN_top]->data *10 + value;
			}
			else
			{
				t = newNode(value,s[i],1); 
				stN_top++;
				stN[stN_top] = t; 
			} 
			isLastDigit = 1;
		} 
		else if (getPriority(s[i]) > 0) 
		{   
			isLastDigit = 0;
			// If an operator with lower or 
			// same associativity appears 
			while ( 
				stC_top != -1 && stC[stC_top] != '('
				&& ((s[i] != '^' && getPriority(stC[stC_top]) >= getPriority(s[i])) 
					|| (s[i] == '^'
						&& getPriority(stC[stC_top]) > getPriority(s[i])))) 
			{ 

				// Get and remove the top element 
				// from the character stack 
				t = newNode(0,stC[stC_top],0);  
				stC[stC_top] = '\0';
				stC_top--;

				// Get and remove the top element 
				// from the node stack 
				t1 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;

				// Get and remove the currently top 
				// element from the node stack 
				t2 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;

				// Update the tree 
				t->left = t2; 
				t->right = t1; 

				// Push the node to the node stack  
				stN_top++;
				stN[stN_top] = t;
			} 

			// Push s[i] to char stack  
			stC_top++;
			stC[stC_top] = s[i];
		} 
		else if (s[i] == ')') { 
		    isLastDigit = 0;
			while ( stC_top != -1 && stC[stC_top] != '(') 
			{ 
				t = newNode(0,stC[stC_top],0);  
				stC[stC_top] = '\0';
				stC_top--;
				t1 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;
				t2 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;
				t->left = t2; 
				t->right = t1;  
				stN_top++;
				stN[stN_top] = t;
			}  
			stC[stC_top] = '\0';
			stC_top--;
		} 
	} 
	t = stN[stN_top]; 
	return t; 
} 

// Function to print the post order 
// traversal of the tree 
void preorder(struct node* root,int i,int n)  
{
	if (root) 
	{  
	    if( root->isValue == 1)
		{   
			printf("%s ",root->s); 
		}
	    else
		{
			printf("%s ",root->s); 
		}
		preorder(root->left,i,n); 
		preorder(root->right,i,n);  
    
	} 
} 

int eval(struct node* root)  
{   
	int temp;
	
    // empty tree  
    if (!root)  
        return 0;  
  
    // leaf node i.e, an integer  
    if (!root->left && !root->right)  
        return root->data;  
  
    // Evaluate left subtree  
    int l_val = eval(root->left);  
  
    // Evaluate right subtree  
    int r_val = eval(root->right);  
    
    switch(root->symbol)
    {
	    case '+':
	            temp=l_val+r_val;break;
	    case '-':
	            temp=l_val-r_val;break;
	    case '*':
	            temp=l_val*r_val;break;
	    case '/':
	            temp=l_val/r_val;break;
	    case '%':
	            temp=l_val%r_val;break;
	    case '^':
	            temp=pow(l_val,r_val);
    }
    return temp;
}  

// Driver code 
int main() 
{ 
	int i,n; 
	char s1[MAX_LIMIT],s2[60],s4[MAX_LIMIT];   
    scanf("%s", s1);    
   	n = strlen(s1);    	
   	s2[0]= '('; 
   	
   	i = 0;
   	while(i<n)
	{
   		if(isValidChar(s1[i]))
		{
   			s2[i+1]=s1[i]; 
		}
		else
		{
	    	printf("Invalid");	
			return 0;		
		} 
		i++; 	
	}
     	
   	s2[i+1]=')'; 
   	

	struct node* root = build(s2,n+2); 
	   
	if(root)
	{		printf("\n%d",eval(root)); 
	}
	else 
	{ 
	    printf("Root is null");
	};

	return 0; 
}