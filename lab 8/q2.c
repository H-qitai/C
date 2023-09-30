#include<stdio.h>

int TimesTwo(int x){
    int result = x * 2;
    return result;
}

int main(){
    int result;
    result = TimesTwo(5);
    printf("Result = %d", result);
}