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

    int i = Get_player_x(cave);
    int j = Get_player_y(cave);

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
    else if (cave[i-1][j] == 'O' && (move == 'w')){
        if (cave[i-2][j] == 0){
            cave[i-2][j] = 'O';
            cave[i-1][j] = 0;
            cave[i][j] = 'X';
        }
        else if (cave[i-2][j] == '*'){
            cave[i-2][j] = 0;
            cave[i-1][j] = 0;
        }
    }
    else if (cave[i][j-1] == 'O' && (move == 'a')){
        if (cave[i][j-2] == 0){
            cave[i][j-2] = 'O';
            cave[i][j-1] = 0;
            cave[i][j] = 'X';
        }
        else if (cave[i][j-2] == '*'){
            cave[i][j-2] = 0;
            cave[i][j-1] = 0;
        }
    }
    else if (cave[i+1][j] == 'O' && (move == 's')){
        if (cave[i+2][j] == 0){
            cave[i+2][j] = 'O';
            cave[i+1][j] = 0;
            cave[i][j] = 'X';
        }
        else if (cave[i+2][j] == '*'){
            cave[i+2][j] = 0;
            cave[i+1][j] = 0;
        }
    }
    else if (cave[i][j+1] == 'O' && (move == 'd')){
        if (cave[i][j+2] == 0){
            cave[i][j+2] = 'O';
            cave[i][j+1] = 0;
            cave[i][j] = 'X';
        }
        else if (cave[i][j+2] == '*'){
            cave[i][j+2] = 0;
            cave[i][j+1] = 0;
        }
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

    return 0;
}



/* The Boulder Break simulation */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;

	InitialiseCave(cave, layout);
	AddItem(cave, 2, 4, "boulder");
	AddItem(cave, 5, 6, "boulder");
	AddItem(cave, 4, 8, "hole");
	AddItem(cave, 1, 4, "treasure");
	AddItem(cave, 4, 5, "player");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}