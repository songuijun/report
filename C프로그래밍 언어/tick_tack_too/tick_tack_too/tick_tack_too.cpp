// tick_tack_too.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#define WIDTH 3
#define HEIGHT 3

int winCheck(int sum)
{
	if (sum == 3)
	{
		printf("Player X wins!\n");
		return 1;
	}
	else if (sum == -3)
	{
		printf("Player O wins!\n");
		return 1;
	}
	return 0;
}
int win(int b[][HEIGHT])
{
	int i, j;
	int sum;
	for (i = 0; i < WIDTH; i++)
	{
		sum = 0;
		for (j = 0; j < HEIGHT; j++)
		{
			sum += b[i][j];
		}

		if (winCheck(sum))
		{
			return 1;
		}
	}
	for (j = 0; j < HEIGHT; j++)
	{
		sum = 0;
		for (i = 0; i < WIDTH; i++)
			sum += b[i][j];
		if (winCheck(sum))
		{
			return 1;
		}
	}
	sum = 0;
	for (i = 0; i < WIDTH; i++)
	{
		sum += b[i][i];
	}
	if (winCheck(sum))
	{
		return 1;
	}
	sum = 0;
	for (i = 0; i < WIDTH; i++)
	{
		sum += b[i][WIDTH - 1 - i];
	}
	if (winCheck(sum)) 
	{ 
		return 1; 
	}
	return 0;
}
void display(int b[][HEIGHT])
{
	char ch;
	int i, j;
	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < WIDTH; i++)
	{
		printf("%d |", i);
		for (j = 0; j < HEIGHT; j++)
		{
			if (b[i][j] == 1)
				ch = 'X';
			else if (b[i][j] == -1)
				ch = 'O';
			else
				ch = ' ';
			printf(" %c", ch);
		}
		printf("\n");
	}
}
int main(void)
{
	int board[3][3];
	char turn = 'X';
	int r, c;
	int i, j;
	int count;
	int lose;
	for (i = 0; i < WIDTH; i++) 
	{
		for (j = 0; j < HEIGHT; j++)
		{
			board[i][j] = 0;
		}
	}
	count = 0;
	display(board);
	do
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);
		printf("\n");
		if (board[r][c]) 
		{
			continue;
		}
		count++;
		if (turn == 'X') 
		{
			board[r][c] = 1;
			turn = 'O';
		}
		else 
		{
			board[r][c] = -1;
			turn = 'X';
		}
		display(board);
	} while ((lose = !win(board)) && count < 9); //count가 9 미만이면 3x3 판 기준으로 다 채워지지 않은 상태
	if (lose && count == 9)
	{
		printf("Nobody wins!\n");
	}
}