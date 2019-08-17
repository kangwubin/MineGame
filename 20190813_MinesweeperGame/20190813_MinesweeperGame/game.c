#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[][COLS], int  rows, int cols, char  set)
{
	int  i = 0;
	int j = 0;
	printf("====================\n");
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void ShowBoard(char board[][COLS], int  row, int col)  //打印是9行9列
{
	int  i = 0;
	int  j = 0;
	for ( i = 0; i <=row; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("====================\n");
}

void SetMine(char mine[][COLS], int  row, int col)
{
	int  x;
	int  y;
	int count = 0;//设置成功一个雷，count++
	while (count < MINE_NUM)
	{
		//x,y设置坐标
		x = rand() % row+1; //[0-9)，加1后为[1-10)
		y = rand() % col + 1;
		if (mine[x][y]=='0')   //初始化时都为字符0
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
//找到有几颗雷,判断XY坐标有几颗雷
static int  GetMineCount(char mine[][COLS],int x, int y)
{
	return mine[x - 1][y - 1] 
	+ mine[x - 1][y] 
	+mine[x - 1][y]
	+mine[x - 1][y+1]
	+mine[x][y+1];
	+mine[x + 1][y + 1]
	+ mine[x + 1][y]
	+ mine[x + 1][y - 1]
	+ mine[x][y - 1] - 8 * '0';
	//数字字符如何转变为它对应的整形数字;ASCLL表   //  '1'-'0'得到整形数字1
}

void FindMine(char mine[][COLS], char mineInfo[][COLS], int row, int col)
{
	//count  :找雷的次数
	int count = 0;
	int x=0;
	int y=0;
	while (count<row*col-MINE_NUM)
	{
		printf("请输入坐标：");
		scanf("%d%d",&x,&y);
		//判断坐标的合法性
		if (x>=1 && x<=9 && y>=1 && y<=9)
		{
			if (mine[x][y]=='1')
			{
				printf("你被炸死了\n");
				ShowBoard(mine, row, col);
			}
			else
			{
				//统计当前位置的周围有几颗雷
				// 输入：1  3坐标
				int ret = GetMineCount(mine,x,y);
				//整形数字转化为数字字符      如：4+'0'='4'
				mineInfo[x][y] = ret + '0';
				ShowBoard(mineInfo,row,col);
				count++;
			}
		}
		else
		{
			printf("坐标不合法");
		}
	}
}
