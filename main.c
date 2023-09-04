#include <stdio.h>
#include <stdlib.h>

void drawBoard(char board[]);
void markBoard(int round, char board[], char *pMark);
int converterLC(int lin, int col);
int checkWin(char board[], int round, char *pMark);


int checkWin(char board[], int round, char *pMark)
{
	// condicional jogo normal
	int winCond = 0;

	// linhas e colunas
	for (int i = 0; i < 3; i++)
	{
		if (board[i * 3] == *pMark && board[i * 3 + 1] == *pMark && board[i * 3 + 2] == *pMark)
			winCond = 1;
		if (board[i] == *pMark && board[i + 3] == *pMark && board[i + 6] == *pMark)
			winCond = 1;
	}

	//diagonais
	if (board[0] == *pMark && board[4] == *pMark && board[8] == *pMark)
		winCond = 1;
	else if (board[2] == *pMark && board[4] == *pMark && board[6] == *pMark)
		winCond = 1;

	// empate
	if (round == 8 && winCond != 1)
		winCond = -1;
	
	return winCond;
}


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


int main()
{   
	char board[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'}, mark, *pMark = &mark;


	drawBoard(board);

	for (int i = 0; i < 9; i++)
	{
		markBoard(i, board, pMark);
		drawBoard(board);
		if(checkWin(board, i, pMark) == 1)
		{
			printf("\nThe big winner is: %c\n", mark);
			break;
		}
		else if(checkWin(board, i, pMark) == -1)
			printf("A tie is a tie man...\n");
	}

	return 0;
}