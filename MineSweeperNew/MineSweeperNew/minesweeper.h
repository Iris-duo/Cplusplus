#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROW 16
#define MAX_COL 16

#define ROWS (MAX_ROW + 2)
#define COLS (MAX_COL + 2)

//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);

//≤º÷√¿◊
void SetMine(char board[ROWS][COLS], int row, int col,int count);

//≈≈¿◊
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int mine_count);