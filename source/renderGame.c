#include <stdio.h>
#include "../headers/funcGame.h"

char board[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'}, mark, *pMark = &mark;

// Renderize the game with the hardcoded board
void render()
{
	drawBoard(board);
	for (int round = 0; round < 9; round++)
	{
		markBoard(round, board, pMark);
		drawBoard(board);
		if(checkWin(board, round, pMark) == 1)
		{
			printf("\nThe big winner is: %c\n", mark);
			break;
		}
		else if(checkWin(board, round, pMark) == -1)
			printf("A tie is a tie man...\n");
	}
}
