#include<stdio.h>

void PrintAverageRainfall(int array[]){
    int i = 0;
    float sum = 0;
    float temp = 0;
    int junk = 0;
    while (array[i] != -999){
        if (array[i] >= 0){
            sum = sum + array[i];
        }
        else if (array[i] < 0){
            temp = temp + array[i];
            junk = junk + 1;
        }
        i++;
}

    sum = ((float)sum / (i-junk));

    if ((sum) < 0){
       printf("no rain");
    }
    else if (sum >= 0){
        printf("%.2f", sum);
    }
    else {
        printf("no rain");
    }
}

int main(){
    int values[1] = {-999};
    PrintAverageRainfall(values);
}