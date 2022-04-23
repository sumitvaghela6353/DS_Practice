//Write a program to implement stack using a singly linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void push(int v){
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

void pop(){
    if(head==NULL){
        printf("The stack is empty.\n");
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
        printf("The stack is empty.\n");
    }
    else{
        struct node* temp;
        temp=head;
        while(temp->next!=NULL){
            printf("%2d  ", temp->data);
            temp=temp->next;
        }
        printf("%2d  \n", temp->data);
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();
    return 0;
}


