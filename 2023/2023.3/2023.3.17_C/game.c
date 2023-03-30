#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include "game.h"

void Inboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1 )
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
		while (1)
		{
			printf("请输入坐标：");
			scanf_s("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (board[x - 1][y - 1] == ' ')
				{
					board[x - 1][y - 1] = '*';
					break;
				}
				else
				{
					printf("该坐标被占用！\n");
				}
			}
			else
			{
				printf("坐标超出棋盘格，请重新输入！\n");
			}
		}
}
void pcmove(char board[ROW][COL], int row, int col)//电脑下棋
{
	int x = 0;
	int y = 0;
	printf("电脑下子：\n");
	while (1)
	{
		x = rand() % row;//生成随机数
		y = rand() % col;
		if (board[x ][y ] == ' ')
		{
			board[x ][y ] = '#';
			break;
		}
	}
}
char isfull(char board[ROW][COL], int row, int col)//平局判断
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char iswin(char board[ROW][COL], int row, int col)//胜利判断
{
	int i = 0;
	for (i = 0; i < row; i++)//行判断
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//列判断
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//斜角判断
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == isfull(board, ROW, COL))//平局判断
	{
		return 'S';
	}
	return 'C';
}