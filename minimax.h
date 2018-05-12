#ifndef MINIMAX_H
#define MINIMAX_H

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int gg(int *winner, int dim, int **board, int mx, int my);
int maximize(int *mx, int *my, int dim, int **board);
int nextMove(int lx, int ly, int dim, int **board, int side);

#endif
