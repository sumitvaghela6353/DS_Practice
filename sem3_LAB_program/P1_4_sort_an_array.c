#include<stdio.h>
#include<stdlib.h>
#define n 5

int digit_count(int b)
{
    int count=0;
    while(b!=0)
    {
        b = b/10;
        count++;
    }
    return count;
}

int main()
{
    int a[n], i, j;
    int temp=0;

    printf("Enter the array: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(digit_count(a[i]) > digit_count(a[j]))
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nElements of array in ascending order: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(digit_count(a[i]) < digit_count(a[j]))
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("\nElements of array in descending order: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    for(i=0; i<n-1; i++)
    {
         for(j=i+1; j<n; j++)
         {
             if(digit_count(a[i]) > digit_count(a[j]))
             {
                 temp = a[i];
                 a[j]=a[i];
                 a[i]=temp;
             }
         }
    }
     return 0;
}
