
#include<stdio.h>
#include<stdlib.h>

// for checking sparse matrix.
int check_sparse(int count, int r, int c){
    if(count <= (r*c)/2){
        return 1;
    }
    else{
        return 2;
    }
}

int main(){
    int a[30][30], b[30][30], r1, c1, i=1, j=1, r2, c2, count1=0, count2=0;
    int s1[30][30], s2[30][30], rs1=1, rs2=1;
    int sa[30][30], l1, l2, k=1;

    printf("Enter the number of row for first sparse-matrix: ");
    scanf("%d", &r1);
    printf("\nEnter the number of column for first matrix: ");
    scanf("%d", &c1);
    printf("\nEnter the number of row for second sparse-matrix: ");
    scanf("%d", &r2);
    printf("\nEnter the number of column for second matrix: ");
    scanf("%d", &c2);

    printf("\nEnter the elements for first matrix: \n");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            printf("Enter element a[%d][%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the elements for second matrix: \n");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            printf("Enter element b[%d][%d]= ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // for counting elements of non-zero numbers

    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            if(a[i][j]!=0){
                count1++;
            }
        }
    }

    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            if(a[i][j]!=0){
                count2++;
            }
        }
    }

    // for checking the matrix is sparse matrix.

    if(check_sparse(count1, r1, c1)==1){
        printf("\nYour matrix is sparse matrix.");
    }
    else{
        printf("\nYour matrix is not sparse-matrix.");
        return 0;
    }


    if(check_sparse(count2, r2, c2)==1){
        printf("\nYour matrix is sparse matrix.");
    }
    else{
        printf("\nYour matrix is not sparse-matrix.");
    }

    //---------------------------------------

    //for displaying matrix-1.

    printf("\nThe first matrix: \n");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }

    // for making sparse matrix.

    s1[0][0]=r1,         s2[0][0]=r2;
    s1[0][1]=c1,         s2[0][1]=c2;
    s1[0][2]=count1,     s2[0][2]=count2;

    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            if(a[i][j]!=0){
                s1[rs1][0]=i;
                s1[rs1][1]=j;
                s1[rs1][2]=a[i][j];
                rs1++;
            }
        }
    }



    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            if(b[i][j]!=0){
                s2[rs2][0]=i;
                s2[rs2][1]=j;
                s2[rs2][2]=b[i][j];
                rs2++;
            }
        }
    }

    printf("\nThe first sparse matrix: \n");

    for(i=0; i<rs1; i++){
        for(j=0; j<3; j++){
            printf("%d  ", s1[i][j]);
        }
        printf("\n");
    }

    //for displaying second matrix.

    printf("\nThe second matrix: \n");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            printf("%2d ", b[i][j]);
        }
        printf("\n");
    }

    printf("\nThe second sparse matrix: \n");

    for(i=0; i<rs2; i++){
        for(j=0; j<3; j++){
            printf("%d  ", s2[i][j]);
        }
        printf("\n");
    }

    //for checking sparse-matrix for addition
    if(s1[0][0]==s2[0][0] && s1[0][1]==s2[0][1]){
        printf("\nAddition is possible.");
    }
    else{
        printf("\nAddition is not possible.");
        exit(0);
    }

    // for addition

    l1 = s1[0][2], l2 = s2[0][2];

    sa[0][0]=s1[0][0];
    sa[0][1]=s1[0][1];
    i=1, j=1, k=1;
    while(i<=l1 && j<=l2){
        if(s1[i][0]==s2[j][0]){
            if(s1[i][1]==s2[j][1]){
                sa[k][0]=s1[i][0];
                sa[k][1]=s1[i][1];
                sa[k][2]=s1[i][2]+s2[j][2];
                i++;
                j++;
                k++;
            }
            else{
                if(s1[i][1]<s2[j][1]){
                    sa[k][0]=s1[i][0];
                    sa[k][1]=s1[i][1];
                    sa[k][2]=s1[i][2];
                    k++;
                    i++;
                }
                else if(s1[i][1]>s2[j][1]){
                    sa[k][0]=s2[j][0];
                    sa[k][1]=s2[j][1];
                    sa[k][2]=s2[j][2];
                    j++;
                    k++;
                }
            }
        }
        else{
            if(s1[i][0] > s2[j][0]){
                sa[k][0]=s2[j][0];
                sa[k][1]=s2[j][1];
                sa[k][2]=s2[j][2];
                k++;
                j++;
            }
            else{
                if(s1[i][0]<s2[j][0]){
                    sa[k][0]=s1[i][0];
                    sa[k][1]=s1[i][1];
                    sa[k][2]=s1[i][2];
                    k++;
                    i++;
                }
            }
        }
    }
    while((j<=l2) && (i>=l1)){
        sa[k][0]=s2[j][0];
        sa[k][1]=s2[j][1];
        sa[k][2]=s2[j][2];
        k++;
        j++;
    }

    while((i<=l1) && (j>=l2)){
        sa[k][0]=s1[i][0];
        sa[k][1]=s1[i][1];
        sa[k][2]=s1[i][2];
        k++;
        i++;
    }
    sa[0][2]=k-1;
    //Displaying Addition.

    printf("\nThe sparse addition is : \n");
    for(i=0; i<k; i++){
        for(j=0; j<3; j++){
            printf("%4d", sa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
