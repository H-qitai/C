#include<stdio.h>
#include<string.h>

char cap(char character){

    int ascii = (int)character - 32;
    char upper = ascii;

    return upper;

}

char sp(char space){

    int ascii = (int)space;
    if (ascii == 32){
        return 1;
    }
}

void Capitalise(char *phrase){

    int i = 0;
    int length = strlen(phrase);

    phrase[i] = cap(phrase[i]);

    for (i = 0; i < length; i++){
        if (sp(phrase[i]) == 1){
            phrase[i+1] = cap(phrase[i+1]);
        }
    }
}


int main(){
    char phrase[100] = "zzzzz";
    Capitalise(phrase);
    printf("%s", phrase);
}