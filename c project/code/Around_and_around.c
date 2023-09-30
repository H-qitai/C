#include<stdio.h>
#include <string.h>

#define CAVE_SIZE 10

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]){
    
    int i = 0;
    int j = 0;

    for (i = 0; i < CAVE_SIZE; i++){
        for (j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 1){
                printf("#");
            }
            else if (cave[i][j] == 'X'){
                printf("X");
            }
            else if (cave[i][j] == 'O'){
                printf("O");
            }
            else if (cave[i][j] == '*'){
                printf("*");
            }
            else if (cave[i][j] == '+'){
                printf("+");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout){
    
    int i = 0;
    int j = 0;
    int lay = 0;

    for (i = 0; i < CAVE_SIZE; i++){
        for (j = 0; j < CAVE_SIZE; j++){
            if (layout[lay] == '1'){
                cave[i][j] = 1;
            }
            else if (layout[lay] == 'E'){
                cave[i][j] = 'E';
            }
            else if (layout[lay] == '0'){
                cave[i][j] = 0;
            }
            lay++;
        }
    }
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element){

    int temp = 0;

    if ((row > CAVE_SIZE) || (col > CAVE_SIZE)){
        return;
    }

    if (cave[row][col] == 0){

        if (strcmp(element, "player") == 0){
            cave[row][col] = 'X';
        }
        else if (strcmp(element, "boulder") == 0){
            cave[row][col] = 'O';
        }
        else if (strcmp(element, "hole") == 0){
            cave[row][col] = '*';
        }
        else if (strcmp(element, "treasure") == 0){
            cave[row][col] = '+';
        }
    }

    for (int i = 0; i < CAVE_SIZE; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 'X'){
                temp++;
            }
        }
    }

    if (temp > 1){
        cave[row][col] = 0;
    } 
}


void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]){

    int temp[CAVE_SIZE][CAVE_SIZE] = {0};

    for (int i = 0; i < CAVE_SIZE; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            temp[j][CAVE_SIZE-i-1] = cave[i][j];
        }
    }

    for (int i = 0; i < CAVE_SIZE; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            cave[i][j] = temp[i][j];
        }
    }
}

int main(){
    char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111";
    int cave[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(cave, layout);
    AddItem(cave, 5, 5, "boulder");
    AddItem(cave, 5, 6, "boulder");
    AddItem(cave, 5, 7, "boulder");
    AddItem(cave, 2, 2, "player");
    printf("Original position:\n");
    PrintCave(cave);
    printf("First rotation:\n");
    RotateCave(cave);
    PrintCave(cave);
    printf("Second rotation:\n");
    RotateCave(cave);
    PrintCave(cave);
    printf("Third rotation:\n");
    RotateCave(cave);
    PrintCave(cave);
    printf("Fourth rotation:\n");
    RotateCave(cave);
    PrintCave(cave);
}