#include<stdio.h>
#include<string.h>
#define MAX_ARRAY_SIZE 1000


void Squeeze(char *word, int maximum){
    
    int i = 1;
    int count = 0;
    char temp[MAX_ARRAY_SIZE] = {'\0'};
    int mem = 0;
    int j = 0;

    if (maximum == 0){
        word[i-1] = '\0';
    }

    while (word[i-1] != '\0'){

        if (word[i-1] != word[i]){
            count++;
            if (count >= maximum){
                while (word[i-1] == word[i]){
                    i++;
                }
                temp[mem] = word[i-1];
                mem++;
                count = 0;
            }
        }
        i++;
    }

    while (temp[j] != '\0'){
        word[j] = temp[j];
        j++;
        if (temp[j] == temp[j+1]){
            word[j] = '\0';
        }
    }
}

int main() {
    char word0[MAX_ARRAY_SIZE] = "LLLLeeeeeeerrrrrooooy Jeeeeeeenkkkins";
    char word1[MAX_ARRAY_SIZE] = "xxxxyyyyxxxyyyxxyyxyxxyyxxxyyyxxxxyyyy";
    char word2[MAX_ARRAY_SIZE] = "OOOKKKKKKKKKK";
    char word3[MAX_ARRAY_SIZE] = "Hello world";
    char word4[MAX_ARRAY_SIZE] = "Hello world";

    Squeeze(word0, 1);
    Squeeze(word1, 1);
    Squeeze(word2, 5);
    Squeeze(word3, 1);
    Squeeze(word4, 0);

    printf("0) %s\n", word0);
    printf("1) %s\n", word1);
    printf("2) %s\n", word2);
    printf("3) %s\n", word3);
    printf("4) %s\n", word4);
}