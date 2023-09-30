#include<stdio.h>

void PrintReverse(int n){

    if (n < 10){
        printf("%d", n);
    }
    else{
        int temp;
        temp = n % 10;
        printf("%d", temp);
        n = n / 10;
        PrintReverse(n);
    }
}

int main(){
    PrintReverse(1359);
}