#include<stdio.h>
#define NUM_ROWS 4
#define NUM_COLS 4

void FindTile(int board[NUM_ROWS][NUM_COLS], int tile, int *rowPos, int *colPos){
	int i, j;

    for (i = 0; i < NUM_ROWS; i++){
        for (j = 0; j < NUM_COLS; j++){
            if (board[i][j] == tile){
                *rowPos = i;
                *colPos = j;
            }
        }
    }

}


int main(){

int board[NUM_ROWS][NUM_COLS] = {
	{-1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	{1, 13, 14, 15}
};
int row, col;

FindTile(board, -1, &row, &col);

printf("Found at %d, %d", row, col);

}
