#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void  menu()
{
	printf("********0.exit********\n");
	printf("********1.play********\n");
	printf("**********************\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};    //存放雷   1代表是雷
	char  mineInfo[ROWS][COLS] = {0};    //排查雷  *
	//代表还没有布置雷
	InitBoard(mine, ROWS, COLS,'0');
	//代表还没有排查出来雷时的情况
	InitBoard(mineInfo, ROWS, COLS, '*');
	//打印二维数组
	//Show(mine,ROW,COL);
	ShowBoard(mineInfo, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//显示设置雷是否成功
	//ShowBoard(mine, ROW, COL);
	//找雷
	FindMine(mine, mineInfo, ROW, COL);
}

int main()
{
	int  input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择 -》");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确的数字\n");
			break;
		}
	} while (input);
}