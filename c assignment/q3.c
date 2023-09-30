#include <stdio.h>

// Helper functions should go here

int isPrime(int num){

    int temp = 1;
    int i = 5;

    if (num <= 1){
        return -1;
    }
    else if ((num % 2) == 0){
        return -1;
    }
    else if ((num % 3) == 0){
        return -1;
    }

    while (temp <= 10000){
        
        if (num == i){
            return 1;
        }
        if (num % i == 0){
            return -1; 
        }
        else {
            temp++;
            i = i + 2;
        }
    }
    return 1;
}

int PrimeBelow(int upper){
    
    int temp = 0;

    if (upper <= 2){
        return -1;
    }

    if (upper == 4){
        return upper-1;
    }

    if (upper == 5){
        return upper-2;
    }

    while (temp != 1){
        upper = upper -1;
        if (isPrime(upper) == 1){
            return upper;
        }
    }
    return upper;
}




int main(){
    int num = 3057;
    /*if (isPrime(num) == 1){
        printf("%d %s\n",num ,"is prime");
    }
    else {
        printf("%d %s\n",num ,"is not prime");
    }*/
    printf("Prime = %d\n", PrimeBelow(10));
}