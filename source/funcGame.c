#include <stdio.h>
#include <stdlib.h>
#include "../headers/directives.h"

void drawBoard(char board[]);
void markBoard(int round, char board[], char *pMark);
int converterLC(int lin, int col);
int checkWin(char board[], int round, char *pMark);

int checkWin(char board[], int round, char *pMark)
{
	int winCond;

	// Check lines and columns. Early return so it don't process any further than necessary
	for (int i = 0; i < 3; i++)
	{
		if (board[i * 3] == *pMark && board[i * 3 + 1] == *pMark && board[i * 3 + 2] == *pMark)
			return WIN;

		if (board[i] == *pMark && board[i + 3] == *pMark && board[i + 6] == *pMark)
			return WIN;
	}

	// Diagonals, early return so it don't process any further than necessary
	if (board[0] == *pMark && board[4] == *pMark && board[8] == *pMark)
		return WIN;

	else if (board[2] == *pMark && board[4] == *pMark && board[6] == *pMark)
		return WIN;

	// Draw, early return not needed
	if (round == 8)
		winCond = DRAW;
	
	return winCond;
}

// Self explanatory draw board function
void drawBoard(char board[])
{
	system("clear");
	for(int i = 0; i < 9; i++)
	{
		printf("%c ", board[i]);
		if(!((i + 1) % 3))
	    		printf("\n");
	}
	printf("\n");
}

// Self explanatory mark board function
void markBoard(int round, char board[], char *pMark)
{
	int lin, col;

	
	if (!(round % 2))
		*pMark = 'x';
	else
		*pMark = 'o';
	
	printf("turno de %c\nDigite uma linha e coluna para marcar: ", *pMark);
	scanf("%d %d", &lin, &col);

	while (board[converterLC(lin, col)] != '-')
	{
		printf("\nPosição já preenchida\nJogador \"%c\", escolher linha e coluna: ", *pMark);
		scanf("%d %d", &lin, &col);		
	}
	
	board[converterLC(lin, col)] = *pMark;
}

// Converts the lines and columns to a unidimensional array, as the board was implemented 
int converterLC(int lin, int col)
{
	int num;

	while (lin < 1 || lin > 3 || col < 1 || col > 3)
	{
		printf("numero inválido, digite uma linha e coluna entre 1 e 3: ");
		scanf("%d %d", &lin, &col);
	}

	if (lin == 1)
		num = col - 1;
	else if (lin == 2)
		num = col + lin;
	else if (lin == 3)
		num = lin + col + 2;

	return num;
}
