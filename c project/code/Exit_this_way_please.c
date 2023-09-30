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

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE]){

    int i = 0;
    int j = 0;
    int mem = 0;
    int temp = 0;

    for (i = 0; i < CAVE_SIZE; i++){
        for (j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 'E'){
                mem++;
            }
        }
    }

    if ((cave[0][0] == 'E') || (cave[0][9] == 'E')|| (cave[9][0] == 'E') || (cave[9][9] == 'E')){
        mem = 0;
    }

    for (i = 0; i < CAVE_SIZE; i++){
        if (cave[i][0] == 'E'){
            temp++;
        }
        else if (cave[i][9] == 'E'){
            temp++;
        }
    }

    for (j = 0; j < CAVE_SIZE; j++){
        if (cave[0][j] == 'E'){
            temp++;
        }
        else if (cave[9][j] == 'E'){
            temp++;
        }
    }

    if (mem != 1 || temp != 1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    char layoutF[200] = "11E1111111100000000110000000011000000001100000000110000000011000000001100000000110000000011111111111";
    int caveF[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(caveF, layoutF);
    PrintCave(caveF);
    printf("Accessible? %d\n", IsExitAccessible(caveF));
}