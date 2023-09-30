#include<stdio.h>

void ConvertToBinary(int n){

    if (n <= 1){
        printf("%d", n);
    }
    else {
        ConvertToBinary(n/2);
        printf("%d", n%2);
    }
}

int main(){
    ConvertToBinary(157);
}