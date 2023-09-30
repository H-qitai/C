#include<stdio.h>

int main(){
    
    int price;
    printf("Total: \n");
    scanf("%d", &price);

    int winners;
    printf("Winners: \n");
    scanf("%d", &winners);

    double result;
    result = (double)price/winners;

    printf("Shared: $%.2f", result);

    return 0;
}