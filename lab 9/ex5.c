/* ENGGEN131 (2022) - Lab 9 (27th - 30th October, 2022)
   EXERCISE FIVE - Sliding Tile Puzzle
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* The dimensions of the puzzle */
#define NUM_ROWS 4
#define NUM_COLS 4

/* Function prototype declaration */
void MakeMove(int board[NUM_ROWS][NUM_COLS], int tile);
void FindTile(int board[NUM_ROWS][NUM_COLS], int tile, int *rowPos, int *colPos);

void PrintBoard(int board[NUM_ROWS][NUM_COLS]);
int GetMove(void);
int GameOver(int board[NUM_ROWS][NUM_COLS]);

/* The main() function for the program.  This defines the starting position of
   the puzzle, and then uses a loop to get a move from the player, and update
   the board.  This loop continues to execute until the board is in the complete
   position */
int main(void)
{
	// The starting configuration of the sliding puzzle pieces
	int board[NUM_ROWS][NUM_COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{-1, 13, 14, 15}
	};
	int row, col;

	// Play the game until the board is in the complete position
	PrintBoard(board);
	while (!GameOver(board)) {
		FindTile(board, -1, &row, &col);
		printf("Empty tile is at row=%d and col=%d.\nMake your move: ", row, col);
		MakeMove(board, GetMove());
		PrintBoard(board);
	}
	printf("Congratulations - you won!");

	return 0;
}

/************************************************************
YOU NEED TO COMPLETE THESE TWO FUNCTIONS ONLY
************************************************************/
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
/************************************************************
YOU NEED TO COMPLETE THESE TWO FUNCTIONS ONLY
************************************************************/




/************************************************************
You do not need to modify any code below this point
************************************************************/
/* This function prints the board */
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

/* Prompt the user to enter a move (which will be an integer representing the tile
they wish to slide), and return this entered value */
int GetMove(void)
{
	int input;
	scanf("%d", &input);
	return input;
}

/* Check the tiles on the board to see if they are in the complete position.  Return
true if the puzzle is completed, and false otherwise */
int GameOver(int board[NUM_ROWS][NUM_COLS])
{
	int i, j;
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if (board[i][j] != 1 + NUM_ROWS*i + j) {
				return ((i == NUM_ROWS-1) && (j == NUM_COLS-1));
			}
		}
	}
	return 0;
}
