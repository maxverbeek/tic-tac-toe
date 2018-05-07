#include <stdio.h>

#include "io.h"

/**
 * Returns log10(n)
 * @param  n int input
 * @return   log base 10 of n
 */
int m_log10(int n) {
	int log = 0;
	int x = 10;

	while (x < n) {
		x = x * 10;
		log++;
	}

	return log;
}

/**
 * Prints the entire board, including a coordinate system.
 * @param dim   Dimension of the board (dim x dim)
 * @param board 2 deminsional int array
 */
void printBoard(int dim, int **board) {

	int numberWidth = m_log10(dim) + 1;

	// 1st row: widest number + 1 space worth of white space
	for (int i = 0; i < numberWidth + 1; i++) putchar(' ');

	// then the numbers
	for (int i = 0; i < dim; i++) printf("%*d ", numberWidth, i);

	// lastly a new line
	putchar('\n');

	for (int y = 0; y < dim; y++) {
		// for each line, left pad the row index with spaces, such
		// that the total width of the number is equal to numberWidth.
		// Then a space follows.
		printf("%*d ", numberWidth, y);

		// Then the contents of the board
		for (int x = 0; x < dim; x++) {
			char fill;

			if (board[y][x] == -1)     fill = 'X';
			else if (board[y][x] == 1) fill = 'O';
			else                       fill = '-';

			// Each coordinate has a width of numberWidth, so as
			// to line up with the top row, and is followed by a space
			printf("%*c ", numberWidth, fill);
		}

		// End with newline
		putchar('\n');
	}
}

/**
 * Puts the player's move in x and y
 * @param x     Player's chosen x-coord
 * @param y     Player's chosen y-coord
 * @param dim   size of the board
 * @param board contents of the board.
 */
void askPlayerMove(int *x, int *y, int dim, int **board) {
	int moved = 0;
	do {
		if (moved) {
			printf("That move is not valid!\n");
		}
		printBoard(dim, board);
		printf("You are playing as X. What is your move? (x, y)\n");
		scanf("%d %d", x, y);
		moved = 1;
	} while (!validMove(*x, *y, dim, board));
}

/**
 * Determines whether the move is a valid move.
 * @param  x     x-location
 * @param  y     y-location
 * @param  dim   dimensions of the board
 * @param  board the board
 * @return       1 if the move is valid, 0 otherwise
 */
int validMove(int x, int y, int dim, int **board) {
	if (x < 0 || x >= dim) return 0;
	if (y < 0 || y >= dim) return 0;
	return board[y][x] == 0;
}
