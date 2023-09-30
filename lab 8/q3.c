#include<stdio.h>

void PrintArray(int values[], int length){
    for (int i = 0; i < length; i++){
        printf("%d ", values[i]);
    }
}

int main(){
    int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintArray(values, 10);
}