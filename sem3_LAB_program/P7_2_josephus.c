//Write a program to implement the josephus problem.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node *next;
};

struct node *last=NULL;

void insert(int data){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=data;
    if(last==NULL){
        last=a;
        a->next=last;
    }
    else{
        a->next=last->next;
        last->next=a;
        last=a;
    }
}

void josephus(int k){
    struct node *head=last->next;
    last->next=head;
    struct node *cur;
    struct node *pre;
    int i;
    cur=head;
    while(cur->next!=cur){
        for(i=1; i<=k; i++){
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        printf("%d is removed\n", cur->data);
        free(cur);
        cur=pre->next;
    }
    printf("The last person is %d\n", cur->data);
}

void display(){
    if(last==NULL){
        printf("The node is empty\n");
    }
    else if(last->next==last){
        printf("%2d  ", last->data);
    }
    else{
        struct node *temp;
        temp=last->next;
        while(temp->next!=last){
            printf("%2d  ", temp->data);
            temp=temp->next;
        }
        printf("%2d  ", temp->data);
        printf("%2d  \n", temp->next->data);
    }
}

int main(){
    int n, i;
    srand(time(0));
    printf("Enter the number: ");
    scanf("%d", &n);
    int k=rand()%n;
    printf("The random number is %d\n", k);
    for(i=1; i<=n; i++){
        insert(i);
    }
    josephus(k);
    // display();
    return 0;
}
