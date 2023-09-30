#include<stdio.h>

int Choose(int n, int m){

    if ((n == m) || (m == 0)){
        return 1;
    }
    else {
        return n*Choose(n-1,m)/(n-m);
    }
}

int main(){
    printf("%d", Choose(52, 5));
}