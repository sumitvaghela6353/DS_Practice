 // write aprogram to insert an element at an appropriate position in an array that is sorted in ascending order.

#include<stdio.h>
int main(){
    int n, i, j, temp, pos, m;
    printf("Enter how many number you want to enter:");
    scanf("%d", &n);
    int a[n+1];
    printf("\nEnter the members: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("\nEnter the number, you want to enter: ");
    scanf("%d", &m);

    for(i=0; i<n; i++){
        if(a[i]>m){
            pos=i;
            break;
        }
    }
    printf("%d", pos);
    for(i=n+1; i>pos; i--){
        a[i]=a[i-1];
    }
    a[pos]=m;

    printf("\nAfter inserting the element: ");
    for(i=0; i<n+1; i++){
        printf("%d, ", a[i]);
    }
    return 0;
}
