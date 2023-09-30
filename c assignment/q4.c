#include<stdio.h>

void ReverseArray(int *values, int left, int right) {

    int i = 0;
    int flip[100] = {0};
    int temp = 0;

    for (i = left; i <= right; i++){
        flip[i] = values[right-temp];
        temp++;
    }
    
    for (i = 0; i <= 100; i++){
        if (i >= left && i <= right){
            values[i] = flip[i];
        }
        else{
            values[i] = values[i];
        }
    }
    
}


int main(){
int values[1] = {9999}; 
ReverseArray(values, 0, 0); 
for (int i = 0; i < 1; i++) { 
   printf("%d ", values[i]); 
}
}