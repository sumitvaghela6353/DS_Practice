/*element a program for a stack that performs following operations using an array: 
a.Push() b.Pop() c.Peep() d.Empty() e.Display()*/

#include<stdio.h>
#include<stdlib.h>
#define max 10

int stack[max];
int top=-1;

void push(int value)
{
    if(top==max-1)
    {
        printf("Stack is full.\n");
    }
    else
    {
        stack[++top]=value;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        return stack[top--];
    }
}

void peep()
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
    }
    else{
        printf("%2d \n", stack[top]);
    }
}

void display(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        for(int i=top; i>-1; i--)
        {
            printf("%2d, ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int i=0;
    int c=5, value;
    do{
        for(int i=0; i<10; i++)
        {
            printf("--");
        }
        printf("\n1.push 2.pop 3.display 4.peep 5.exit\n");
        printf("Enter your choise: ");
        scanf("%d", &c);

        switch(c){
            case 1:
                printf("Enter number: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                printf("Your pop value is %d.\n", pop());
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Your top value is ");
                peep();
                break;

            case 5:
                c=5;
                break;

            default:
                printf("Your choise is wrong, please try again.\n");
        }
    }
    while(c!=5);
    return 0;
}
