#include <stdio.h>


int CountZeros(int values[], int length)
{
    int i, count;

    count = 0;
    for (i = 0; i < length; i++) {
        if (values[i] == 0) {
            count++;
        }
    }

    return count;
}


int main(){

    int values[5] = {0,1};
    printf("%d", CountZeros(values, 5));

}