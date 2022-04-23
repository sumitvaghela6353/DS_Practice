#include<stdio.h>
int main()
{
    int arr[20],i,j;
    int n, count=0, temp=0;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
    {
            if(arr[i]==arr[j])
            {
                temp=arr[j];
                arr[j]=arr[n-1];
                arr[n-1]=temp;
                n--;
            }

        }
    }

    printf("The array:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
