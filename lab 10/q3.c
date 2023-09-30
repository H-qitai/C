#include<stdio.h>
#include<string.h>


int IsSuffix(char *suffix, char *word){

    int i = 0;
    int length_s = strlen(suffix);
    int length_w = strlen(word);

    if (length_s > length_w){
        return 0;
    }

    for (i = length_w; i >= 0; i--){
        if (word[length_w-1] == suffix[length_s-1]){
            return 1;
        }
    }
    return 0;
}


int main(){
    printf("Result = %d\n", IsSuffix("shear", "ear"));
}