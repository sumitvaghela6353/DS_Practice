//Delete an element by its value from array.

#include<stdio.h>
int main(){
    int n, i, pos=0, value, flag=0;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element you want to delete: ");
    scanf("%d", &value);

    for(i=0; i<n; i++){
        if(a[i]==value){
            pos = i;
            flag=1;
        }
    }
    if(flag==0){
        printf("\nThe element is not in the array.");
    }

    for(i=pos; i<n-1; i++){
        a[i]=a[i+1];
    }

    printf("\nArray after deleting element: ");
    for(i=0; i<n-1; i++){
        if(i==n-2){
            printf("%d ", a[i]);
        }
        else{
            printf("%d, ",a[i]);
        }
    }
    return 0;
}
