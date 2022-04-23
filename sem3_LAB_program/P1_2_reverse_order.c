#include<stdio.h>
void reverse(int* arr, int size)
{
    int *ptr=arr+size-1;
    for(int i=0; i<size; i++)
    {
        printf("%d, ", *(ptr-i));
    }
}
int main(){
    int a[10];
    int n;
    printf("Enter how many number you want to enter: ");
    scanf("%d", &n);
    printf("Enter the array:\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter the %d element: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("The reverse order:\n");
    reverse(a,n);
    return 0;
}
