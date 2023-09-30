#include<stdio.h>

int LastIndexOf(int search, int values[], int numValues){
    int temp, mem, i;
    mem = 0;
    temp = 0;
    for (i = 0; i < numValues;){
        if (values[i] == search){
            temp = i;
            mem = 1 + mem;
        }
        i++;
    }
    if (mem <= 0){
        return -1;
        }
    return temp;
}


int main(){    	
    int values[5] = {1,2,0,2,1};
    int pos = LastIndexOf(2, values, 5);
    printf("%d", pos);
}
