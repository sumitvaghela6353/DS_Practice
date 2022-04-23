//Write a program to implement a priority queue using an array.

#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int MAX=5,q[5];

void insert(int v)
{
    if(rear==MAX-1)
    {
     printf("priority queue is full");
    }

    else
    {
        int j=rear;
        if(front==-1)
        {
        front=0;
        }
        while(j>=0 && v<q[j])
        {
            q[j+1]=q[j];
            j--;
        }
        q[j+1]=v;
        rear=rear+1;
    }
}

void delete()
{
    if(front==rear+1)
     printf("empty");
    else
    {
        printf("your element is delete\n");
        front=front+1;
    }
}

void display()
{
   if(front==rear+1)
     printf("queue is empty");
   else
   {
       for(int i=front;i<=rear;i++)
        printf("%d ",q[i]);
   }
}


int main()
{
    int value,n;
    do
    {
        printf("\n1.insert 2.delete 3.display 4.exit\n");
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
    } while (n!=4);
    return 0;
}
