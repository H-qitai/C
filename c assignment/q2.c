#include<stdio.h>

void RemoveLetterAt(char *word, int position){

    int length = sizeof(word) / sizeof(word[0]);

    for (int i = position; i < length; i++)
    {
       word[i] = word[i+1];
    }
}


int main(){

char word[100] = "hello";
RemoveLetterAt(word, 4);
printf("Result = (%s)", word);

}