#include<stdio.h>

int main(){

    int a;
    printf("Enter the first value in the sequence: \n");
    scanf("%d", &a);

    int d;
    printf("Enter the difference between consecutive values: \n");
    scanf("%d", &d);

    int n;
    printf("Enter the number of values in the sequence: \n");
    scanf("%d", &n);

    double sum;
    sum = (n*a) + ((double)n/2) * (d*n - d);
    printf("Sum = %.0f", sum);

    return 0;
}