/*Write a program to implement a queue using an array that can perform following operations:
 Insert
 Delete
 Display*/

#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int MAX=5,q[5];
void insert(int v)
{
    if(rear==MAX-1)
    {
     printf("queue is full");
    }
    else if(front==-1)
    {
        front=0;
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
    if(front==rear+1)
     printf("queue is empty");
    else
    {
        printf("your element delete\n");
        front=front+1;
    }
}

void display()
{
   if(front==rear+1)
     printf("queue is empty");
   else
   {

       for( int i=front;i<=rear;i++)
       {
        printf("%d ",q[i]);
       }

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

        }
    } 
    while (n!=4);
    return 0;
}
