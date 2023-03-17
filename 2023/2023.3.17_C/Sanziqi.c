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
	Inboard(board, ROW, COL);//��ʼ������
	Displayboard(board,ROW, COL);//��ӡ����
	while (1)//����ѭ��
	{
		playermove(board, ROW, COL);//�������
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
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else if (ret == 'S')
	{
		printf("ƽ��\n");
	}
}
void menu()
{
	printf("    1��play    0��exit \n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL) );//��ʱ�����������
	do
	{
		printf("������1��0��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
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