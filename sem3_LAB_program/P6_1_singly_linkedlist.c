/*Write a menu driven program to implement following operations on the singly linked list.
� Insert a node at the front of the linked list.    � Insert a node at the end of the linked list.
� Insert a node at a given position.      � Delete a first node of the linked list.
� Delete a last node of the linked list.        � Delete a node from the specified position.*/

#include<stdio.h>
#include<stdlib.h>

struct node* head=NULL;
struct node{
    int data;
    struct node *next;
};

void insert_beg(int v){                                   //insert at the begining
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=v;
    if(head==NULL){
        a->next=NULL;
        head=a;
    }
    else{
        a->next=head;
        head=a;
    }
}

void insert_end(int v){                                 //insert at the end value
    struct node* a=(struct node*)malloc(sizeof(struct node));
    struct node* temp=NULL;
    if(head==NULL){
        a->data=v;
        a->next=NULL;
        head=a;
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=a;
        a->data=v;
        a->next=NULL;
    }
}

void insert_pos(int pos_v, int v){              //insert after given value
    int flag=0;
    struct node *temp;
    temp=head;
    if(head==NULL){
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        a->next=NULL;
        head=a;
    }
    else{
        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->data=v;
        while(temp->data!=pos_v)
        {
            if(temp->next==NULL){
                printf("Node is not found, don't insert data.\n");
                flag=1;
                break;
            }
            else{
                temp=temp->next;
            }
        }
        if(flag==0){
            a->next=temp->next;
            temp->next=a;
        }
    }
}

//delete node at the beginning
void delete_beg(){
    struct node* temp;
    if(head==NULL){
        printf("Node is empty.\n");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        printf("Your value has been deleted.\n");
    }
}

//delete node at the end
void delete_end(){
    struct node* temp;
    if(head==NULL){
        printf("The node is empty.\n");
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        printf("Your value has been deleted.\n");
    }
}

//DELETE after the POS_VALUE
void delete_afterValue(int data){
    struct node *temp;
    struct node *p;
    temp=head;
    int flag=0;
    if(head==NULL){
        printf("The node is empty.\n");
    }
    else{
        while(temp->data!=data){
            if(temp->next==NULL){
                printf("The node is not found.\n");
                flag=1;
                break;
            }
            else{
                temp=temp->next;
            }
        }

        if(flag==0){
            p=temp->next;
            temp->next=p->next;
            free(p);
            printf("Your value has been deleted.\n");
        }
    }
}

void display(){
    struct node *a;
    if(head==NULL){
        printf("linked list is empty.\n");
    }
    else{
        for(a=head; a!=NULL; a=a->next){
            printf("%d\t", a->data);
        }
        printf("\n");
    }
}

int main(){
    int n, value, data;
    do{
        printf("1.insert at the beginning 2.insert at the ending 3.insert after the given value 4.delete at the beginning  5.delete at the ending 6.delete after the given value 7.display 8.exit\n");
        printf("Enter your choice:");
        scanf("%d", &n);
        for(int i=0; i<15; i++){
            printf("---");
        }
        printf("\n");
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
                insert_pos(data, value);
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
                printf("The linked list: \n");
                display();
                break;

            case 8:
                n=8;
                break;

            default:
                printf("Wrong choise!!!\n");
                break;
        }
        for(int i=0; i<15; i++){
            printf("---");
        }
        printf("\n");
    }while(n!=8);
    return 0;
}
