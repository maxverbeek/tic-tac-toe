#include "minimax.h"

/**
 * Determines if the game is over in the board. The last move
 * is always the winning move, and therefore the consecutive
 * positions will include given x and y coordinates.
 * @param  winner The winner of the game
 * @param  dim    size of the board
 * @param  board  contents of the board
 * @param  mx     final x move
 * @param  my     final y move
 * @return        true if the game is over, false otherwise
 */
int gg(int *winner, int dim, int **board, int mx, int my) {
	// For now, the winner is the person that made the last move.
	// Can be changed to draw if appropriate.
	*winner = board[my][mx];

	// diagonal check (0, 0  ->  n, n)
	if (mx == my) {
		int n;
		for (n = 0; n < dim; n++) {
			if (board[n][n] != *winner) break;
		}

		if (n == dim) return 1;
	}

	// antidiagonal check (0, n  ->  n, 0)
	if (mx + my == dim - 1) {
		int x;
		for (x = 0; x < dim; x++) {
			int y = dim - 1 - x;
			if (board[y][x] != *winner) break;
		}

		if (x == dim) return 1;
	}

	// column check (fixed x, variable y)
	int y;
	for (y = 0; y < dim; y++) {
		if (board[y][mx] != *winner) break;
	}

	if (y == dim) return 1;

	// row check (fixed y, variable x)
	int x;
	for (x = 0; x < dim; x++) {
		if (board[my][x] != *winner) break;
	}

	if (x == dim) return 1;

	// no solution found, test if there are still empty spots. If there are,
	// the game can still continue. If there aren't -> draw.
	for (int y = 0; y < dim; y++) {
		for (int x = 0; x < dim; x++) {
			if (board[y][x] == 0) {
				*winner = 0;
				return 0;
			}
		}
	}

	*winner = 0;
	return 1;
}

void maximize() {
	// todo
}

void minimize() {
	// todo
}

