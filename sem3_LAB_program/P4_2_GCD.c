//Write a program to calculate the GCD of two numbers using recursive function.

#include <stdio.h>
int GCD(int n1, int n2);
int main()
{
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf("G.C.D of %d and %d is %d.", n1, n2, GCD(n1, n2));
    return 0;
}

int GCD(int n1, int n2) {
    if (n2 != 0)
        return GCD(n2, n1 % n2);
    else
        return n1;
}
