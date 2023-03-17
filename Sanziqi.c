#define _CRT_SECURE_NO_WARINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include "game.h"

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	Inboard(board, ROW, COL);//初始化棋盘
	Displayboard(board,ROW, COL);//打印棋盘
	while (1)//下棋循环
	{
		playermove(board, ROW, COL);//玩家下棋
		Displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		pcmove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else if (ret == 'S')
	{
		printf("平局\n");
	}
}
void menu()
{
	printf("    1、play    0、exit \n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL) );//由时间生成随机数
	do
	{
		printf("请输入1或0：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);

}

int main()
{
	menu();
	test();
	return 0;
}