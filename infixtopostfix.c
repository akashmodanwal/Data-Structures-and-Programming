/**
*Title: Infix to Postfix conversion
*File : infixtopostfix.cpp
*Author: Akash Modanwal
*date:   December 2020
*couse:  DSP Lab
*
*purpose of program:	
*				This program is implemenatation of Infix to Postfix converion.
*
**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//node initialization
struct node
{

char data;
struct node *next;


}*top=NULL,*pstart=NULL;

//This function inserts new node 
void insert(char ch)
{
struct node *t,*new;
    new=(struct node *)malloc(sizeof(struct node));
    new->next=NULL;
    new->data=ch;
    t=pstart;

    if(pstart==NULL)
    {
    pstart=new;
    }
    else
    {
    while(t->next!=NULL)
    t=t->next;
    t->next=new;

    }


}



//stack push operation

void push (char symbol)
{

    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=symbol;
    if(top==NULL)
    {
     top=p;
     p->next=NULL;

    }
    else
    {

    p->next=top;
    top=p;

    }
}

//stack pop operation

char  pop()
{
struct node *x,*y;
char k;
if(top==NULL)
{
    printf("stack underflow\n");
    return 0;

}
else
{
x=top;
top=top->next;
k=x->data;
free(x);
x=NULL;
return k;


}



}

//displayes postfix expression

void displaypost()
{
    struct node *to;
    if(pstart==NULL);
    else
    {
    to=pstart;
    while(to!=NULL)
    {
        printf("%c",to->data);
        to=to->next;

    }

    }


}

//defines precedence of operators

int precedence(char ch)
{

if(ch=='^')
return (4);
else if(ch=='*' || ch== '/')
return (3);
else if (ch== '+' || ch== '-')
return (2);
else
return (-1);
}

//This function changes infix to postfix
void intopost(char infix[])
{

    int len;
    int index=0;
    char symbol,temp;
    len= strlen(infix);
    while(len>index)
    {
        symbol=infix[index];

        switch(symbol)
        {

        case '(':
        push(symbol);
        break;

        case ')':
        temp=pop();
        while(temp!='(')
        {
        insert(temp);
        temp=pop();
        }
        break;

        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
        if(top==NULL)
        {
            push(symbol);

        }
        else
        {
        while(top!=NULL && (precedence(top->data)>=precedence(symbol)))
        {
            temp=pop();
            insert(temp);

        }
        push(symbol);

        }   
        break;
        default:
        insert(symbol);

         }
         index=index+1;


    }
    while(top!=NULL)
    {
    temp=pop();
    insert(temp);

    }
    displaypost();
    return;




}

//Driver function

int main()
{
char infix[50];
scanf("%[^\n]%*c",infix); //removing spaces
intopost(infix);
return 0;
}
