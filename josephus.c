/* Title : Implementation of Josephus Problem
*File : josephus.c
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*			This program is implementation of Josephus Problem.It takes number of soldiers and skip position in every step.
	
* References:
*			https://cp-algorithms.com/others/josephus_problem.html
**/
#include <stdio.h> 

/*
* void josephus(int n,int k)
*	summary:
*		This function solves Josephus problem and returns winner's position by formula.
*	Parameters:
*		int n : number of soldiers
*		int k : skiped position in every step
*	Return value :
*		int : winner's position
*/
int josephus(int n, int k) 
{ 
if (n == 1) 
	return 1; 
else
	return (josephus(n - 1, k) + k-1) % n + 1;   //this recursion formula returns winner's position
} 

// Main Function
int main() 
{ 
int n,k; 
printf("Implement Josephus Problem \n");
printf("---------------------------\n");
printf("Enter no of soldiers and number that has to be skiped in every step\n");
scanf("%d",&n);
scanf("%d",&k); 
printf("Soldier that will be saved is %d", josephus(n, k)); 
return 0; 
} 
//end of program
