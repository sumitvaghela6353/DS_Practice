/*Write a menu driven program to implement following operations on a singly circular linked list.
     Insert a node at the front of the linked list.
     Insert a node at the end of the linked list.
     Insert a node at a given position.
     Delete a first node of the linked list.
     Delete a last node of the linked list.
     Delete a node from the specified position.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head=NULL;

void insert_beg(int v)
{
    if(head==NULL)
    {
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        a->next=a;
        head=a;
    }
    else
    {
        struct node* a=(struct node*)malloc(sizeof(struct node));
        struct node* temp;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        a->data=v;
        a->next=head;
        temp->next=a;
        head=a;

    }
}

void insert_end(int v)
{
    if(head==NULL)
    {
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        a->next=a;
        head=a;
    }
    else
    {
        struct node*temp;
        temp=head;
        struct node* a=(struct node*)malloc(sizeof(struct node));
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        a->data=v;
        a->next=head;
        temp->next=a;
    }
}

void insert_after(int v,int pos_v)
{
    if(head==NULL)
    {
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        a->next=a;
        head=a;
    }
    else
    {
        struct node*temp;
        temp=head;
        struct node* a=(struct node*)malloc(sizeof(struct node));
        while(temp->data!=pos_v)
        {
            if(temp->next==head)
             printf("you are enter a wrong value");
            else
             temp=temp->next;
        }
        a->data=v;
        a->next=temp->next;
        temp->next=a;
    }
}
void delete_beg()
{
    if(head==NULL)
     printf("the node is empty");
    else
    {
        struct node*temp;
        temp=head;
        while(temp->next!=head)
        {
          temp=temp->next;
        }

        struct node* p=head;
        head=head->next;
        temp->next=head;
        free(p);

    }
}

void delete_end()
{
    if(head==NULL)
     printf("the node is empty");
    else
    {
        struct node*temp;
        temp=head;
        while(temp->next->next!=head)
        {
          temp=temp->next;
        }
        struct node* p=temp->next;
        temp->next=head;
        free(p);
    }

}

void delete_after(int pos_v)
{
    if(head==NULL)
     printf("the node is empty");
    else
    {
        struct node*temp;
        temp=head;
        while(temp->data!=pos_v)
        {
            if(temp->next==head)
            {
                printf("you enter a wrong value");
            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp->next==head)
        {
            delete_beg();
        }
        else{
            struct node*j=temp->next;
            temp->next=j->next;
            free(j);
        }

      }
}

void display()
{
    if(head==NULL)
     printf("the node is empty");
    else
     {
         struct node *i;
         for(i=head;i->next!=head;i=i->next)
         {
             printf("%d ",i->data);
         }
          printf("%d",i->data);
     }
}

int main()
{
    int n,value,data,posv;
    do
    {
        printf("\n1.insert at beg 2.insert at end 3.insert at after 4.delete at beg 5.delete at end 6.delete after 7.display 8.exit\n");
        printf("enter a your choice");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
             printf("enter a value");
             scanf("%d",&value);
             insert_beg(value);
             break;

            case 2:
              printf("enter a value");
              scanf("%d",&value);
              insert_end(value);
              break;

            case 3:
              printf("enter a value");
              scanf("%d",&value);
              printf("enter a data you want enter after a data");
              scanf("%d",&posv);
              insert_after(value,posv);
              break;
            case 4:
              delete_beg();
              break;

            case 5:
               delete_end();
               break;

            case 6:
                printf("enter a data you want enter after a data");
                scanf("%d",&posv);
                delete_after(posv);
                break;

            case 7:
               display();
               break;

            case 8:
             exit(1);
             break;

            default :
            printf("you enter a wrong choice");
        }
    } while (n!=8);
    return 0;

}
