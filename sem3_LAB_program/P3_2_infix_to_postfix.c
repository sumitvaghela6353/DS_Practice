//Write a program to convert infix expression into postfix expression.

#include<stdio.h>
#include<stdlib.h>
#define max 20

char stack[max];
int top=-1;

void push(char v){
    if(top==max-1){
        printf("Stack is full.\n");
    }
    else{
        stack[++top]=v;
    }
}

int pop(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        return stack[top--];
    }
}

void display(){
    int temp=top;
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        for(int i=temp; i>-1; i--){
            printf("%2d, ", stack[i]);
        }
        printf("\n");
    }
}

int pres(char x){          //pres=parenthasis
    if(x=='(')
    {
        return 0;
    }
    else if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    else if(x=='^' || x=='$')
    {
        return 3;
    }
}

int main(){
    char str[20];
    char *e, x;
    printf("Enter the expression: ");
    scanf("%s", str);
    e=str;
    while(*e!='\0')
    {
        if(isalnum(*e))  //alphanumeric
        {
            printf("%c", *e);
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while((x=pop())!='('){
                printf("%c", x);
            }
        }
        else{
            while(pres(stack[top])>=pres(*e)){
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c", pop());
    }
    return 0;
}















