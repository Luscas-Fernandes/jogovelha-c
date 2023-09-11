#include <stdio.h>
#include "funcGame.h"

int main()
{   
	char board[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'}, mark, *pMark = &mark;


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

	return 0;
}
