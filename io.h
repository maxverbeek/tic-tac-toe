#ifndef IO_H
#define IO_H

int m_log10(int n);
void printBoard(int dim, int **board);
void askPlayerMove(int *x, int *y, int dim, int **board);
int validMove(int x, int y, int dim, int **board);

#endif
