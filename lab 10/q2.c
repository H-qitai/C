#include<stdio.h>

void Censor(char *phrase, int left, int right){

    int i = 0;

    for (i = 0; i <= 100; i++){
        if (i >= left && i <= right){
            phrase[i] = *"X";
        }
        else{
            phrase[i] = phrase[i];
        }
    }
}

int main(){
    char censor[100] = "ENGGEN131";
    Censor(censor, 6, 8);
    printf("%s\n", censor);
}