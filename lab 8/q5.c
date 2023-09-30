#include<stdio.h>

void PrintSummary(int array[]){
    int i = 0;
    int neg = 0;
    int pos = 0;

    while (array[i] != 0){
        if (array[i] < 0){
            neg = neg + 1;
        }
        else if (array[i] > 0){
            pos = pos + 1;
        }
        i++;
    }

    if (pos == neg){
        printf("Equal");
    }
    else if (pos > neg){
        printf("Positive");
    }
    else {
        printf("Negative");
    }
}

int main(){
    int values[4] = {1, 2, 3, 0};
    PrintSummary(values);
}