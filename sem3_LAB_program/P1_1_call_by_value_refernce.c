#include<stdio.h>

int swap_value(int a, int b)
{
    int temp;
    a=temp;
    a=b;
    b=temp;
    return a,b;
}

void swap_reference(int* x, int* y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    // return *x,*y;
}

int main(){

    int a,b;
    int n;
    printf("Enter the two num:\n");
    scanf("%d %d", &a, &b);
    printf("choise:\n1. Call by value\n2. Call by reference\n");
    printf("Enter the choise: ");
    scanf("%d", &n);
    switch(n){
        case 1:
            swap_value(a,b);
            printf("a=%d  b=%d", a,b);
            break;
        case 2:
            swap_reference(&a, &b);
            printf("a=%d  b=%d", a,b);
            break;

        default:
            printf("Wrong choise.");
            break;
    }
    return 0;
}
