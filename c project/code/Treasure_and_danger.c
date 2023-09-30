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


int main(){
    	
    char layoutB[200] = "1111111111111000011111100001111110000111111000011111100001111110000111111000011111100001111111E11111";
    int caveB[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(caveB, layoutB);
    AddItem(caveB, 1, 3, "player");
    AddItem(caveB, 1, 4, "player");
    AddItem(caveB, 1, 5, "player");
    AddItem(caveB, 1, 6, "player");
    AddItem(caveB, 1, 3, "boulder");
    AddItem(caveB, 1, 4, "boulder");
    AddItem(caveB, 1, 5, "boulder");
    AddItem(caveB, 1, 6, "boulder");
    AddItem(caveB, 2, 3, "boulder");
    AddItem(caveB, 2, 4, "boulder");
    AddItem(caveB, 2, 5, "boulder");
    AddItem(caveB, 2, 6, "boulder");
    AddItem(caveB, 3, 1, "boulder");
    AddItem(caveB, 3, 2, "boulder");
    AddItem(caveB, 3, 3, "boulder");
    AddItem(caveB, 7, 6, "hole");
    AddItem(caveB, 8, 4, "treasure");
    AddItem(caveB, 123456, 123456, "treasure");
    PrintCave(caveB);
}