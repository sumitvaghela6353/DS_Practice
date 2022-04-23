/*Write a menu driven program to implement following operations on the doubly linked list.
• Insert a node at a given position.
• Delete a node from the specified position.
• Display the nodes of doubly linked list.*/


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

void insert_beg(int v){
    if(head==NULL){
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        a->next=NULL;
        a->prev=NULL;
        head=a;
    }
    else{
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        a->next=head;
        a->prev=NULL;
        head->prev=a;
        head=a;
    }
}

void insert_end(int v){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=v;
    if(head==NULL){
        a->next=NULL;
        a->prev=NULL;
        head=a;
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=a;
        a->next=NULL;
        a->prev=temp;
    }
}

void insert_afterValue(int v, int data){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=v;
    int flag=0;
    if(head==NULL){
        a->next=NULL;
        a->prev=NULL;
        head=a;
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->data!=data){
            if(temp->next==NULL){
                printf("Node is not found.\n");
                flag=1;
                return;
            }
            else{
                temp=temp->next;
            }
        }
        if(flag==0){
            a->next=temp->next;
            temp->next->prev=a;
            temp->next=a;
            a->prev=temp;
        }
    }
}

void insert_beforeValue(int v, int data){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=v;
    int flag=0;
    if(head==NULL){
        a->next=NULL;
        a->prev=NULL;
        head=a;
    }
    else if(head->data==data){
        insert_beg(v);
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->data!=data){
            if(temp->next==NULL){
                printf("Node is not found.\n");
                flag=1;
                return;
            }
            else{
                temp=temp->next;
            }
        }
        if(flag==0){
            a->next=temp;
            temp->prev->next=a;
            a->prev=temp->prev;
            temp->prev=a;
        }
    }
}

void delete_beg(){
    if(head==NULL){
        printf("node is empty.\n");
    }
    else{
        struct node *temp;
        temp=head;
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
}

void delete_end(){
    if(head==NULL){
        printf("Node is empty.\n");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}

void delete_afterValue(int data){
    int flag=0;
    if(head==NULL){
        printf("Node is empty.\n");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->data!=data){
            if(temp->next==NULL){
                printf("Node is not found.\n");
                flag=1;
                return;
            }
            else{
                temp=temp->next;
            }
        }
        if(flag==0){
            struct node *p;
            p=temp->next;
            temp->next=temp->next->next;
            p->next->prev=temp;
            free(p);
        }
    }
}

void delete_beforeValue(int data){
    int flag=0;
    if(head==NULL){
        printf("Node is empty.\n");
    }
    else if(head->data==data){
        printf("It is already deleted.\n");
    }
    else if(head->next->data==data){
        delete_beg();
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->data!=data){
            if(temp->next==NULL){
                printf("Node is not found.\n");
                flag=1;
                return;
            }
            else{
                temp=temp->next;
            }
        }
        if(flag==0){
            struct node *p;
            p=temp->prev;
            temp->prev->prev->next=temp;
            temp->prev=p->prev;
            free(p);
        }
    }
}

void display(){
    if(head==NULL){
        printf("The linked list is empty.\n");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=NULL){
            printf("%2d  ", temp->data);
            temp=temp->next;
        }
        printf("%2d\n", temp->data);
    }
}

int main(){
int n, v,value, data;
    do{
        printf("1.insert at the beginning 2.insert at the ending 3.insert after the given value 4.delete at the beginning 5.delete at the ending 6.delete after the given value 7.insert before the value 8.Delete before the values 9.Display 10.exit\n");
        printf("Enter your choice:");
        scanf("%d", &n);
        for(int i=0; i<10; i++){
        }
        printf("");
        switch(n){
            case 1:
                printf("Enter number:");
                scanf("%d", &value);
                insert_beg(value);
                break;

            case 2:
                printf("Enter the number:");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the number after you want to enter:");
                scanf("%d", &data);
                insert_afterValue(v, data);
                break;

            case 4:
                delete_beg();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter the number which after you want to delete: ");
                scanf("%d", &data);
                delete_afterValue(data);
                break;

            case 7:
                printf("Enter the value: ");
                scanf("%d", &v);
                printf("Enter the data before you want to enter: ");
                scanf("%d", &data);
                insert_beforeValue(v,data);
                break;

            case 8:
                printf("Enter the data after you want to delete: ");
                scanf("%d", &data);
                delete_beforeValue(data);
                break;

            case 9:
                printf("The linked list: \n");
                display();
                break;

            case 10:
                n=10;
                break;

            default:
                printf("Wrong choise!!!\n");
                break;
        }
        for(int i=0; i<10; i++){
            printf("---");
        }
        printf("\n");
    }while(n!=10);
    return 0;
}
