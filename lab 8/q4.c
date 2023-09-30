#include<stdio.h>

int SumPositiveValues(int values[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++){
        if (values[i] > 0) {
            sum = sum + values[i];
        }
    }
    return sum;
}

int main(){
    int values[11] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int sum = SumPositiveValues(values, 11);
    printf("%d", sum);
}