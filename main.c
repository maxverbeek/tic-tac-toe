#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "io.h"
#include "minimax.h"

int main(int argc, char const *argv[]) {

	srand(time(NULL));

	int boardSize = 3;

	int **board = malloc(boardSize * sizeof(int *));

	for (int i = 0; i < boardSize; i++) {
		// initialize board to 0
		board[i] = calloc(boardSize, sizeof(int));
	}

	int playerTurn = rand() > (RAND_MAX / 2);
	int winner = 0;
	int x, y, mark;

	do {

		if (playerTurn) {
			askPlayerMove(&x, &y, boardSize, board);
			mark = -1;
		} else {
			maximize(&x, &y, boardSize, board);
			mark = 1;
		}

		// Mark the chosen location on the board, and swap turns.
		board[y][x] = mark;
		playerTurn = !playerTurn;
	} while (! gg(&winner, boardSize, board, x, y));

	if (winner == -1) {
		printf("You win!\n");
	} else if (winner == 1) {
		printf("You lose!\n");
	} else {
		printf("Tie!\n");
	}

	// Clean up board
	for (int y = 0; y < boardSize; y++) {
		free(board[y]);
	}

	free(board);
	
	return 0;
}
