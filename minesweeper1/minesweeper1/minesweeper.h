//#pragma once
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define ROW 9
//#define COL 9
//
//#define ROWS ROW+2
//#define COLS COL+2
//
//#define EASY_COUNT 10
//
////声明函数
//
////初始化棋盘	
//void InitBoard(char arr[ROWS][COLS], int rows, int cols,char set);
////打印棋盘
//void DisplayBoard(char arr[ROWS][COLS], int row, int col);
////布置雷
//void SetMine(char arr[ROWS][COLS], int row, int col);
////排查雷
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 棋盘最大尺寸（数组按最大值开，实际行列由难度决定）
#define MAX_ROW 16
#define MAX_COL 16

#define ROWS (MAX_ROW + 2)
#define COLS (MAX_COL + 2)

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

// 打印玩家看到的棋盘（带颜色）
void DisplayBoard(char show[ROWS][COLS], int row, int col);

// 布置雷（首次点击后再调用，safe_x/safe_y 周围不布雷，保证首点安全）
void SetMine(char mine[ROWS][COLS], int row, int col, int count, int safe_x, int safe_y);

// 排查雷（游戏主循环）
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int mine_count);