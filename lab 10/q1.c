#include<stdio.h>
#include<string.h>

int IsPalindrome(char *word){

    char flip[100] = "0";
    int temp = 0;
    int length = strlen(word);
    int mem = 0;

    for (int i = 0; i <= length; i++){
        flip[i] = word[length-1-temp];
        temp++;
    }

    for (int i = 0; i < length; i++){
        if (flip[i] == word[i]){
            mem++;
            if (mem == length){
                return 1;
            }
        }
    }

    return 0;
}


int main(){
    char word[100] = "abba";
    printf("%d", IsPalindrome(word));
}