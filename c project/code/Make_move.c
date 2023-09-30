#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 5

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

    int temp[CAVE_SIZE][CAVE_SIZE];

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


int Get_player_x(int cave[CAVE_SIZE][CAVE_SIZE]){

    int row;

    for (int i = 0; i < CAVE_SIZE; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 'X'){
                return row = i;
            }  
        }
    }

    return 0;

}

int Get_player_y(int cave[CAVE_SIZE][CAVE_SIZE]){

    int col;

    for (int i = 0; i < CAVE_SIZE; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 'X'){
                return col = j;
            }
        }
    }
    return 0;
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move){

    int i = Get_player_x(cave);
    int j = Get_player_y(cave);
    int k = 0;

    if (cave[i-1][j] == 0 && (move == 'w')){
        cave[i-1][j] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i][j-1] == 0 && (move == 'a')){
        cave[i][j-1] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i+1][j] == 0 && (move == 's')){
        cave[i+1][j] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i][j+1] == 0 && (move == 'd')){
        cave[i][j+1] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i-1][j] == 'E' && (move == 'w')){
        cave[i-1][j] = 'X';
        cave[i][j] = 0;
        return 2;
    }
    else if (cave[i][j-1] == 'E' && (move == 'a')){
        cave[i][j-1] = 'X';
        cave[i][j] = 0;
        return 2;
    }
    else if (cave[i+1][j] == 'E' && (move == 's')){
        cave[i+1][j] = 'X';
        cave[i][j] = 0;
        return 2;
    }
    else if (cave[i][j+1] == 'E' && (move == 'd')){
        cave[i][j+1] = 'X';
        cave[i][j] = 0;
        return 2;
    }
    else if (cave[i-1][j] == '*' && (move == 'w')){
        cave[i-1][j] = '*';
        cave[i][j] = 0;
        return 1;
    }
    else if (cave[i][j-1] == '*' && (move == 'a')){
        cave[i][j-1] = '*';
        cave[i][j] = 0;
        return 1;
    }
    else if (cave[i+1][j] == '*' && (move == 's')){
        cave[i+1][j] = '*';
        cave[i][j] = 0;
        return 1;
    }
    else if (cave[i][j+1] == '*' && (move == 'd')){
        cave[i][j+1] = '*';
        cave[i][j] = 0;
        return 1;
    }
    else if (cave[i-1][j] == '+' && (move == 'w')){
        cave[i-1][j] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i][j-1] == '+' && (move == 'a')){
        cave[i][j-1] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i+1][j] == '+' && (move == 's')){
        cave[i+1][j] = 'X';
        cave[i][j] = 0;
    }
    else if (cave[i][j+1] == '+' && (move == 'd')){
        cave[i][j+1] = 'X';
        cave[i][j] = 0;
    }


    else if (cave[i-1][j] == 'O' && (move == 'w')){
        while (k <= CAVE_SIZE){
            if ((cave[i-2-k][j] == 0)){
                cave[i-2-k][j] = 'O';
                cave[i-1-k][j] = 0;
            }
            else if(cave[i-2-k][j] == '*'){
                cave[i-2-k][j] = 0;
                cave[i-1-k][j] = 0;
                k = CAVE_SIZE;
            }
            else{
                k = CAVE_SIZE;
            }
            k++;
        }
    }

    else if (cave[i][j-1] == 'O' && (move == 'a')){
        while (k <= CAVE_SIZE){
            if ((cave[i][j-2-k] == 0)){
                cave[i][j-2-k] = 'O';
                cave[i][j-1-k] = 0;
            }
            else if(cave[i][j-2-k] == '*'){
                cave[i][j-2-k] = 0;
                cave[i][j-1-k] = 0;
                k = CAVE_SIZE;
            }
            else{
                k = CAVE_SIZE;
            }
            k++;
        }
    }

    else if (cave[i+1][j] == 'O' && (move == 's')){
        while (k <= CAVE_SIZE){
            if ((cave[i+2+k][j] == 0)){
                cave[i+2+k][j] = 'O';
                cave[i+1+k][j] = 0;
            }
            else if(cave[i+2+k][j] == '*'){
                cave[i+2+k][j] = 0;
                cave[i+1+k][j] = 0;
                k = CAVE_SIZE;
            }
            else{
                k = CAVE_SIZE;
            }
            k++;
        }
    }

    else if (cave[i][j+1] == 'O' && (move == 'd')){
        while (k <= CAVE_SIZE){
            if ((cave[i][j+2+k] == 0)){
                cave[i][j+2+k] = 'O';
                cave[i][j+1+k] = 0;
            }
            else if(cave[i][j+2+k] == '*'){
                cave[i][j+2+k] = 0;
                cave[i][j+1+k] = 0;
                k = CAVE_SIZE;
            }
            else{
                k = CAVE_SIZE;
            }
            k++;
        }
    }
    return 0;
}

int main(){
char layout[200] = "111111000110001100011E111";
int cave[CAVE_SIZE][CAVE_SIZE];
InitialiseCave(cave, layout);
AddItem(cave, 1, 1, "player");
AddItem(cave, 2, 2, "boulder");
AddItem(cave, 3, 1, "hole");

PrintCave(cave);
MakeMove(cave, 'd');PrintCave(cave);
MakeMove(cave, 's');PrintCave(cave);
MakeMove(cave, 'a');PrintCave(cave);
MakeMove(cave, 'a');PrintCave(cave);
MakeMove(cave, 'w');PrintCave(cave);
MakeMove(cave, 'a');PrintCave(cave);
MakeMove(cave, 's');PrintCave(cave);
MakeMove(cave, 's');PrintCave(cave);
MakeMove(cave, 's');PrintCave(cave);

PrintCave(cave);
}