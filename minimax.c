#include <limits.h>

#include "io.h"
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

/**
 * Picks the best move for player "1"
 * @param  bx    x-coordinate of best move
 * @param  by    y-coordinate of best move
 * @param  dim   dimension of the board
 * @param  board the board
 * @return       the best value "1" can get.
 */
int maximize(int *bx, int *by, int dim, int **board) {
	// game still going
	int highest = INT_MIN;

	for (int y = 0; y < dim; y++) {
		for (int x = 0; x < dim; x++) {
			if (board[y][x] != 0) continue;

			board[y][x] = 1;
			int val = nextMove(x, y, dim, board, -1);
			board[y][x] = 0;

			if (val > highest) {
				*bx = x;
				*by = y;
				highest = val;
			}
		}
	}

	return highest;
}

/**
 * Determines the next best move for side
 * @param  lx    last x-coordinate
 * @param  ly    last y-coordinate
 * @param  dim   dimension of the board
 * @param  board the board
 * @param  side  the side that should make a move (-1 or 1)
 * @return       the best outcome for side
 */
int nextMove(int lx, int ly, int dim, int **board, int side) {
	int winner;
	if (gg(&winner, dim, board, lx, ly)) return winner;

	// side == 1  means maximizing (optimal starts at -infinity)
	// side == -1 means minimizing (optimal starts at  infinity)
	int optimal = side == 1 ? INT_MIN : INT_MAX;

	for (int y = 0; y < dim; y++) {
		for (int x = 0; x < dim; x++) {
			// only try moves on spots that are not filled in yet
			if (board[y][x] != 0) continue;

			// temporarily set the move, and calculate best move for opposite
			// side. Then reset board and try a different move
			board[y][x] = side;
			int val = nextMove(x, y, dim, board, -1 * side);
			board[y][x] = 0;

			// if this move was optimal for "side", update the best move value.
			if ((side == 1 && val > optimal) || (side == -1 && val < optimal)) {
				optimal = val;
			}
		}
	}

	return optimal;
}
