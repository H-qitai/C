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



void MakeMove(int board[NUM_ROWS][NUM_COLS], int tile){
    int row_neg, col_neg;
    FindTile(board, -1, &row_neg, &col_neg);

    int row, col;
    FindTile(board, tile, &row, &col);
    
    if (((row_neg-row)+(col_neg-col)) == 1){
        if ((row_neg - row) == 1){
        board[row_neg][col] = tile;
        board[row][col] = -1;
    }
    else if ((row_neg - row)== -1){
        board[row_neg][col] = tile;
        board[row][col] = -1;
    }
    else if ((col_neg - col)== 1){
        board[row][col_neg] = tile;
        board[row][col] = -1;
    }
    else if ((col_neg - col)== -1){
        board[row][col_neg] = tile;
        board[row][col] = -1;
    }
    }
    else if (((row_neg-row)+(col_neg-col)) == -1){
        if ((row_neg - row) == 1){
        board[row_neg][col] = tile;
        board[row][col] = -1;
    }
    else if ((row_neg - row)== -1){
        board[row_neg][col] = tile;
        board[row][col] = -1;
    }
    else if ((col_neg - col)== 1){
        board[row][col_neg] = tile;
        board[row][col] = -1;
    }
    else if ((col_neg - col)== -1){
        board[row][col_neg] = tile;
        board[row][col] = -1;
    }
    } 
}



void PrintBoard(int board[NUM_ROWS][NUM_COLS])
{
	int i, j;
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if (board[i][j] == -1) {
				printf(" _ ");
			} else if (board[i][j] > 9) {   // align two-digit numbers
				printf(" %d", board[i][j]);
			} else {
				printf(" %d ", board[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
    int board[NUM_ROWS][NUM_COLS] = {
	{1, 2, 3, 4},
	{5, 6, -1, 8},
	{9, 10, 11, 12},
	{16, 13, 14, 15}
    };

    MakeMove(board, 10);

    PrintBoard(board);
}

