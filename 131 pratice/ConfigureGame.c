#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int ConfigureGame(char name[]){

    printf("Please enter your name(under 30 characters): ");
    scanf("%s", &name);
    int guesses = 0;
    printf("\nPlease enter the max guesses from 1 to 20: ");
    scanf("%d", &guesses);
    if (guesses <= 20 && guesses >= 1){
        return guesses;
    }
    else{
        printf("\nPlease enter the max guesses from 1 to 20: ");
        scanf("%d", &guesses);
    }
    
}

int GenerateTarget(char configFile[ ]){
    printf("asd");
}

int main(){
    
    char username[30];
    int MaxG, target, guessMade[20], NumGuess;

    MaxG = ConfigureGame(username);
    target = GenerateTarget("config.txt");

}