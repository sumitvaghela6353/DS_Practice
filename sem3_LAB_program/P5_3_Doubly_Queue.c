//Write a program to implement a doubly queue using an array.

#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int MAX=5,q[5];

void insert_front(int v)
{
    if((front==rear+1)||(front==0 && rear==MAX-1))
    {
     printf("double ended queue is full");
     return;
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
    {
        front=MAX-1;
    }
    else
    {
        front=front-1;
    }
    q[front]=v;
}

void insert_rear(int v)
{
    if((front==0 && rear==MAX-1)||(front==rear+1))
    {
        printf("double ended queue is full");
        return;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
     q[rear]=v;
}

void delete_front()
{
    if(front==-1)
    {
     printf("empty");
    }
    else{
    printf("your element is delete\n");
     if(front==rear)
     {
         front=-1;
         rear=-1;
     }
     else if(front==MAX-1)
     {
         front=0;
     }
     else
     {
         front=front+1;
     }
    }
}

void delete_rear()
{
    if(front==-1)
    {
     printf("empty");
    }
    else
    {
    printf("your element is delete");
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        rear=MAX-1;
    }
    else
    {
        rear=rear-1;
    }
    }
}

void display()
{
     if(front==-1)
    {
     printf("empty");
    }
   else if(front<rear)
    {
        for(int i=front;i<=rear;i++)
         printf("%d ",q[i]);
    }
    else
    {
        for(int i=front;i<MAX;i++)
         printf("%d ",q[i]);

        for(int i=0;i<=rear;i++)
         printf("%d ",q[i]);
    }
}


int main()
{
    int value,n;
    do
    {
        printf("\n1.insert_front n2.insert_rear n3.delete_front n4.delete_rear n5,display n6.exit\n");
        printf("enter a choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
             printf("enter a value:");
             scanf("%d",&value);
             insert_front(value);
             break;
            case 2:
             printf("enter a value:");
             scanf("%d",&value);
             insert_rear(value);
             break;
            case 3:
             delete_front();
             break;
            case 4:
             delete_rear();
             break;
            case 5:
             display();
             break;
            case 6:
             exit(1);

             default:
              printf("you enter a wrong value");
        }
    }while(n!=6);
    return 0;
}
