#ifndef    _Game_H_
#define   _Game_H_
#include<stdio.h>
#include<stdlib.h>  //rand()
#include<time.h>//�����������
#define  MINE_NUM 10  //�����׵�����

#define ROW 9
#define COL 9

#define ROWS  ROW+9
#define COLS   COL+9 
//��ʼ������
void InitBoard(char board[][COLS],int  rows,int cols,char  set);

void ShowBoard(char board[][COLS], int  row, int col);

void SetMine(char mine[][COLS], int  row, int col);

void FindMine(char mine[][COLS], char mineInfo[][COLS], int row, int col);

#endif