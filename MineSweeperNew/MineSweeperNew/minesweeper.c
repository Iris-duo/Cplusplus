#define _CRT_SECURE_NO_WARNINGS 1
#include"minesweeper.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	printf("-----MineSweeper-----\n");
	for (j = 0; j <= cols; j++)
		printf("%2d ", j);              // 打印列号 1 2 3 ...
		printf("\n");

		for (i = 1; i <= rows; i++)
		{
			printf("%2d ", i);              // 每行开头打印行号
			for (j = 1; j <= cols; j++)
				printf(" %c ", board[i][j]); // 打印这一行的每个格子
			printf("\n");                   // 一行打完换行
		}
		printf("-----MineSweeper-----\n");
}

//布置雷
	void SetMine(char mine[ROWS][COLS], int row, int col, int count)
	{
		while (count > 0)
		{
			int x = rand() % row + 1;   // 随机行：1 ~ row
			int y = rand() % col + 1;   // 随机列：1 ~ col

			if (mine[x][y] == '0')      // 这个位置还没雷
			{
				mine[x][y] = '1';       // 放一颗
				count--;                // 待放的雷少一颗
			}
			// 如果这个位置已经是雷了：什么都不做，while 再转一圈重新随机
		}
	}

	static int GetMineCount(char mine[ROWS][COLS], int x, int y)
	{
		return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
			+ mine[x][y - 1] + mine[x][y + 1]
			+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]
			- '0' * 8;
	}

	void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int mine_count)
	{
		int x = 0;
		int y = 0;
		int win = 0;                          // 已经安全翻开的格子数
		int target = row * col - mine_count;  // 目标：翻开所有非雷格

		while (win < target)
		{
			printf("请输入要排查的坐标:> ");
			scanf("%d %d", &x, &y);

			if (x >= 1 && x <= row && y >= 1 && y <= col)   // 坐标合法吗
			{
				if (show[x][y] == '*')                      // 这格还没翻过
				{
					if (mine[x][y] == '1')                  // 踩雷了！
					{
						printf("很遗憾，你踩到雷了\n");
						DisplayBoard(mine, row, col);
						break;                              // 跳出循环，游戏结束
					}
					else                                    // 安全
					{
						int count = GetMineCount(mine, x, y);
						show[x][y] = count + '0';           // 数字变字符，写回show
						DisplayBoard(show, row, col);
						win++;
					}
				}
				else
				{
					printf("该坐标已经排查过，请重新输入\n");
				}
			}
			else
			{
				printf("坐标无效，请重新输入\n");
			}
		}

		if (win == target)
			printf("恭喜你，排查成功\n");
	}