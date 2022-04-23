// Delete an element from a given position in array.

#include<stdio.h>
int main()
{ 
    int n, i, pos;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the position, you want to delete: ");
    scanf("%d", &pos);
    for(i=pos; i<n; i++)
    {
        a[i]=a[i+1];
    }
    printf("\nArray after deleting the element: ");
    for(i=0; i<n-1; i++)
    {
        printf("%d, ", a[i]);
    }
    return 0;
}
