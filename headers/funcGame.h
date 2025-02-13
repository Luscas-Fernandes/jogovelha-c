#pragma once

void drawBoard(char board[]);
void markBoard(int round, char board[], char *pMark);
int converterLC(int lin, int col);
int checkWin(char board[], int round, char *pMark);