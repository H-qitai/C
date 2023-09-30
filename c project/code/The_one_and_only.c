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

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]){

    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < CAVE_SIZE; i++){
        for (j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 'E'){
                temp++;
            }
        }
    }

    if (temp != 1){
        return 0;
    }
    else {
        return 1;
    }
}

int main(){
    char layoutC[200] = "1111111111E0000EE0110000000011000000001100000000110000000011000000001100000000110000000011111111111";
    int caveC[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(caveC, layoutC);
    PrintCave(caveC);
    printf("Unique? %d\n", IsExitUnique(caveC));

    }