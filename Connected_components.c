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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph {
    int Ver;
    struct node** adjLists;
};

struct node* createNode(int vertex) {                               // Createing node
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int Ver)                                  // Createing  graph
{
    int i;
    
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->Ver = Ver;
    
    graph->adjLists = malloc(Ver * sizeof(struct node*));
    
    for (i = 0; i < Ver; i++)
        graph->adjLists[i] = NULL;
    
    return graph;
}

void addingEdge(struct Graph* graph, int source, int destination)           // Adding  edge
{
    
    struct node* newNode = createNode(destination);                         // Add edge from source to destination
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;
    
    newNode = createNode(source);                                           // Add edge from destination to source
    newNode->next = graph->adjLists[destination];
    graph->adjLists[destination] = newNode;
}
void graphPrint(struct Graph* graph)                                            //graph  printing
{
    int v;
     
    for (v = 0; v < graph->Ver; v++) 
    {
        struct node* temporary = graph->adjLists[v];
        printf("\nVertex %d : ", v+1);
        while (temporary) 
        {
            printf("%d -> ", temporary->vertex+1);
            temporary = temporary->next;
        } 
    }
}

void DepthFirstSearch(int vertex, bool visited[], struct Graph* graph)
{ 
    visited[vertex] = true; 
    printf("%d ",vertex+1);
    
    struct node* temporary = graph->adjLists[vertex]; 
    while (temporary) 
    {   
        if (!visited[temporary->vertex])
            DepthFirstSearch(temporary->vertex, visited, graph);
        temporary = temporary->next;
    } 
}

void ConnectedComponents(struct Graph* graph)
{
    int v,c = 1;                                                    //count connected component
    bool visited[graph->Ver]; 
    
    for (v = 0; v < graph->Ver; v++)                                // Mark all the vertices as not visited 
        visited[v] = false;
 
    for ( v = 0; v < graph->Ver; v++) {
        if (visited[v] == false) 
        {
            printf("\nComponent: %d Vertices: ",c);                     // print all reachable vertices
            DepthFirstSearch(v, visited, graph); 
            c++;
        }
    }
    
    c--;   
    printf("\n\nNumber of connected Components = %d\n", c);

    if(c == 1)
        printf("\nThe given graph is a Connected Graph\n");
    else
        printf("\nThe given graph is NOT a Connected Graph\n");

}
int main()                               // Driver code 
{
    int node,edges,i,source,destination;
    FILE *fp1;// creating a FILE variable
    char c[30];
	printf("Enter Input txt file's' path  :\t");
	gets(c);
    fp1 = fopen(c, "r"); // open the file

    if (fp1 == NULL)                                            //checking the opening of file
    {   
        printf("\nError : File is not found\n");               //displaying if error occur
        exit(0); 
    } 
    
    fscanf(fp1, "%d %d", &node,&edges);                         //reading nos of node and edge from file
    printf("\nNumber of vertices read from txt : %d ",node); 
    printf("\nNumber of edges read from txt : %d",edges); 
    
    if(edges > node*(node-1)/2)                                 //Validating  number of edges
    {   
        printf("\nInvalid number of edges");
        return 0;
    }
    
    struct Graph* graph = createGraph(node);                    //graph creation
    
    for(i=1;i<=edges;i++)
    {
        fscanf(fp1, "%d %d", &source, &destination);            //input from file
        printf("\nEdge %d read from file between vertices: %d and %d",i,source,destination); 
        source = source - 1;
        destination = destination -1 ;

        if((source == -1) && (destination == -1))
            break;

        if( source >= node || destination >= node || source<0 || destination<0)
        {
            printf("\nInvalid edge\n");
            i--;
        }
        else                                     
            addingEdge(graph, source, destination);         //Adding Edge 
    }
    
                                                            //Printing Graph
    printf("\n\nAdjacency List representation of given Undirected Graph:");
    graphPrint(graph);
    
    printf("\n\nList of Connected components:\n");
    ConnectedComponents(graph);                         //Getting Connected Components 
    
    return 0;
} 


