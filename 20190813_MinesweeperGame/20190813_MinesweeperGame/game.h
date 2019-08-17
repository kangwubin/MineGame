#ifndef    _Game_H_
#define   _Game_H_
#include<stdio.h>
#include<stdlib.h>  //rand()
#include<time.h>//设置随机种子
#define  MINE_NUM 10  //设置雷的数量

#define ROW 9
#define COL 9

#define ROWS  ROW+9
#define COLS   COL+9 
//初始化棋盘
void InitBoard(char board[][COLS],int  rows,int cols,char  set);

void ShowBoard(char board[][COLS], int  row, int col);

void SetMine(char mine[][COLS], int  row, int col);

void FindMine(char mine[][COLS], char mineInfo[][COLS], int row, int col);

#endif