// write a program to insert an element an at a given position in an array.

#include<stdio.h>
int main(){
    int n, i, j, pos, m;
    printf("Enter number of element: ");
    scanf("%d",&n);
    int a[n+1];
    printf("\nEnter members: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);  
    }
    printf("\nEnter the position(starting from 1): ");
    scanf("%d", &pos);
    printf("\nEnter element: ");
    scanf("%d", &m);
    for(i=n+1; i>pos-1; i--)
    {
        a[i] = a[i-1];
    }
    a[pos-1]=m;
    printf("\nAfter insering new member: \n");
    for(i=0; i<n+1; i++){
        printf("%d, ", a[i]);
    }
    return 0;
}
