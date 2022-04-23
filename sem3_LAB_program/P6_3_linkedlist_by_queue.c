//Write a program to implement queue using a singly linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insert(int v){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=v;
    if(head==NULL){
        a->next=NULL;
        head=a;
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        a->next=NULL;
        temp->next=a;

    }
}

void delete(){
    if(head==NULL){
        printf("q is empty.\n");
    }
    else{
        struct node* temp;
        temp=head;
        head=head->next;
        free(temp);
    }
}

void display(){
    if(head==NULL){
        printf("The q is empty.\n");
    }
    else{
        struct node* temp;
        temp=head;
        while(temp->next!=NULL){
            printf("%2d  ", temp->data);
            temp=temp->next;
        }
        printf("%2d\n", temp->data);
    }
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    delete();
    delete();
    display();
    return 0;
}
