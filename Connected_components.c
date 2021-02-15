/* 
* Title : computr connected components in an undirected graph
*File : connected_components.c
*Author: Akash Modanwal
*date:  January 2021
*couse: DSP Lab
*
*purpose of program:	
*			It finds connected components in an undirected graph
**/
#include<stdio.h>
#include<stdlib.h>

struct node   //Crate a node of struct type
{
      int data;
      struct node *link;
};

struct node *arr[10];   //for text file 
int mark_arr[10];


void disp(int V)  //Function for display the Adjacency list
{
	printf("\nThe Adjacency List is: \n");
	int i;
	struct node *prober=arr[0];
	for(i=1;i<=V;i++)
	{
		prober=arr[i];
		while(prober)  //prober from beginning to end of the list
		{
			printf("%d->%d ",i,prober->data);   //print the Adjacency list data 
			prober=prober->link;
		}
		printf("\n");
	}
	return;
}


void ConComp(int V)   //Function for count the number of connectedd components 
{
	int marker=0,grpCount=1;    //marker->used for group number
	int i;
	
	for(i=0;i<10;i++)           //loop for initialize mark array with 0   (0,0,0,0.......)
		mark_arr[i]=0;
	
	struct node *prober=arr[0];    //initialize the first potion of prober
	for(i=1;i<=V;i++)
	{
		if(mark_arr[i]==0)
		{
			mark_arr[i]=grpCount;   //1  1+1=2
			grpCount++;
		}
		
		marker=mark_arr[i];
		
		prober=arr[i];
		while(prober)
		{
			if(mark_arr[prober->data]==0)     //check to see if the vertex is already mark with the gp number 
			{
				mark_arr[prober->data]=marker;  //the vertex with the current gp number
				prober=prober->link;             //changed prober point to the next node
			}
			
			else 
			{
				if(mark_arr[prober->data]<marker)    //Check to see if the current gp number is less then the vertices privious gp number
				{
					struct node *probe2=arr[i]; 
					int marker2=mark_arr[prober->data]; //to set the marker with the value of lower gp number
					while(probe2!=prober)    //changes the gp number for the whole list
					{
						mark_arr[probe2->data]=marker2;
						probe2=probe2->link;
					}
					marker=mark_arr[prober->data];   //Change the value of marker with the old value of marker
				}
				else mark_arr[prober->data]=marker;  
   				
				prober=prober->link;
			}	
			
		}
	}
	printf("The number of connected components is %d\n",grpCount-1);
	return;
}


void main()     //Start the main Function
   {  
	
       struct node *prober;   //traverse the list
	int i=0,d,V,E;        //V->Vertices ,E->Edges 
	
	for(i=0;i<10;i++)    //Initialize the adjacency list with NULL
	     arr[i]=NULL;
	
	char ch1,ch2;        //Reads the characters from input text file
	
	ch1 = getchar();     //Reads the first character from the input text file 
	V=ch1-'0';           //Converts character to integer data types 
	                     //52-48=4
	ch1 = getchar();     //Reads the white space
	ch2 = getchar();     //Reads the next character from the input text file 
	E=ch2-'0';           //Converts character to integer data types 
	ch2 = getchar();     //Reads the new line Characters 
	
	while(ch2!=EOF||ch1!=EOF)    //End of file character
	{
		ch1 = getchar();     //Reads the first character 
		if(ch1==EOF) break;  //here we check to see the end of file
		
		struct node *new_node=(struct node *)malloc(sizeof(struct node)); // Dynamic memory Allocation
		new_node->link=NULL;  
		d=ch1-'0';
			
		ch2 = getchar();
		if(ch2==EOF) break;
	
		ch2 = getchar();
		if(ch2==EOF) break;
		new_node->data=ch2-'0';   //stores the converted value into new node
		
		prober=arr[d];    //start form vertex 1
		if(arr[d]!=NULL)  
		{
			
			while(prober->link)
				prober=prober->link;
			
			prober->link=new_node;
			
		}
		else arr[d]=new_node;
				
		ch2=getchar(); //Reads the new line character
	}

	disp(V);   //call the display function of Adjacency list
	ConComp(V);  // call the connected component function
	return;
}



