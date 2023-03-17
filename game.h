#define ROW 3
#define COL 3

#include <time.h>

void Inboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void pcmove(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL], int row, int col);