/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

// Task One: InitialiseStory
void InitialiseStory(char* paragraph){

    char story[2000] = {"A dumb adventurer named Steve is stuck in a dark cold cave with no light. Bob has to acquire a Minecraft torch in order to survive in the dark cold cave. The cave has multiple types of monsters such as creeper, skeleton, zombies. Steve has to push boulders to unlock different routes to the cave and get the ender dragon egg."};
    int mem = 0;
    int i = 0;
    int temp = 0;

    while (story[i] != '\0'){

        paragraph[i+temp] = story[i];

        if ((mem >= 50) && (paragraph[i+temp] == ' ')){
            temp++;
            paragraph[i+temp] = '\n';
            mem = 0;
        }
        mem++;
        i++;
    }
}

// Task Two: PrintCave
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

// Task Three: InitialiseCave
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

// As you work on the other tasks, remove the comments below
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
        if (cave[i][0] != 1){
            temp++;
        }
        else if (cave[i][9] != 1){
            temp++;
        }
    }

    for (j = 0; j < CAVE_SIZE; j++){
        if (cave[0][j] != 1){
            temp++;
        }
        else if (cave[9][j] != 1){
            temp++;
        }
    }

    if (temp >= 2 || mem != 1){
        return 0;
    }
    else {
        return 1;
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

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE]){

    int mem = 1;

    if ((cave[0][0] == 'E') || (cave[0][9] == 'E')|| (cave[9][0] == 'E') || (cave[9][9] == 'E')){
        mem = 0;
    }

    return mem;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element){

    int temp = 0;

    if (cave[row][col] == 0){

        if (element == "player"){
            cave[row][col] = 'X';
        }
        else if (element == "boulder"){
            cave[row][col] = 'O';
        }
        else if (element == "hole"){
            cave[row][col] = '*';
        }
        else if (element == "treasure"){
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
        cave[row][col] = '0';
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

int Get_player_x(int cave[CAVE_SIZE][CAVE_SIZE]){

    int row;

    for (int i = 0; i < CAVE_SIZE; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            if (cave[i][j] == 'X'){
                return row = i;
            }
        }
    }

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

}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move){

    int row = Get_player_x(cave);
    int col = Get_player_y(cave);

    if (cave[row-1][col] == 0 && (move == 'w')){
        cave[row-1][col] = 'X';
        cave[row][col] = 0;
    }
    else if (cave[row][col-1] == 0 && (move == 'a')){
        cave[row][col-1] = 'X';
        cave[row][col] = 0;
    }
    else if (cave[row+1][col] == 0 && (move == 's')){
        cave[row+1][col] = 'X';
        cave[row][col] = 0;
    }
    else if (cave[row][col+1] == 0 && (move == 'd')){
        cave[row][col+1] = 'X';
        cave[row][col] = 0;
    }

}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};

	InitialiseStory(story);
	InitialiseCave(cave, layout);
	PrintCave(cave);

	return 0;
}