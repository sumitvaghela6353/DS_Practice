//Write a program to implement a circular queue using an array.

#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int MAX=3,q[4];

void insert(int v)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("queue is full");
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

void delete()
{
    if(front==-1){
     printf("empty");
    }
    else{
    printf("your element is delete");
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

void display()
{
    if(front==-1)
     printf("empty");
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
        printf("\n1.insert n2.delete n3.display n4.exit\n");
        printf("enter a choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
             printf("enter a value:");
             scanf("%d",&value);
             insert(value);
             break;
            case 2:
             delete();
             break;
            case 3:
             display();
             break;
            case 4:
             exit(1);
            default:
              printf("you enter a wrong value");
        }
    } while (n!=4);
    return 0;
}
