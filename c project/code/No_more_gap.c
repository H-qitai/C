#include <stdio.h>
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

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE]){

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
        if (cave[i][0] == 0){
            temp++;
        }
        else if (cave[i][9] == 0){
            temp++;
        }
    }

    for (j = 0; j < CAVE_SIZE; j++){
        if (cave[0][j] == 0){
            temp++;
        }
        else if (cave[9][j] == 0){
            temp++;
        }
    }

    if (temp > 0 && mem != 1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    	
    char layoutE[200] = "1EEEEEEEE01EEEEEEEE11EEEEEEEE11EEEEEEEE11EEEEEEEE11EEEEEEEE11EEEEEEEE11EEEEEEEE11EEEEEEEE11EEEEEEEE1";
    int caveE[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(caveE, layoutE);
    PrintCave(caveE);
    printf("Complete? %d\n", IsBorderComplete(caveE));
}