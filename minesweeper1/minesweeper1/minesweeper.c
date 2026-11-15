//#define _CRT_SECURE_NO_WARNINGS 1
//#include"minesweeper.h"
//
////初始化棋盘
//void InitBoard(char arr[ROWS][COLS], int rows, int cols,char set)
//{
//	int i = 0;
//	for (i = 0; i < rows; i++)
//	{
//		int j = 0;
//
//		for(j = 0; j < cols; j++)
//		{
//				arr[i][j] = set;	
//		}
//	}
//}
////打印棋盘	
//void DisplayBoard(char arr[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	//打印列号
//	printf("\n");
//	printf("-----mineweeper-----\n");
//	for(i = 0; i <= col; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		int j = 0;
//		printf("%d ", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("-----mineweeper-----\n");
//	printf("\n");
//}
//
////布置雷	
//void SetMine(char arr[ROWS][COLS], int row, int col)
//{
//	int count = EASY_COUNT;
//	while(count)
//	{
//		int x = rand() % row + 1;	//1~9
//		int y = rand() % col + 1;	//1~9
//		if(arr[x][y] == '0')
//		{
//			arr[x][y] = '1';
//			count--;
//		}
//	}
//}
//
//static int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	return mine[x - 1][y - 1] + 
//		mine[x - 1][y] + 
//		mine[x - 1][y + 1] +
//		mine[x][y - 1] + 
//		mine[x][y + 1] +
//		mine[x + 1][y - 1] + 
//		mine[x + 1][y] + 
//		mine[x + 1][y + 1] - '0' * 8;
//}
//
////排查雷	
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	int win = 0;	
//	while (win<row*col-EASY_COUNT)
//	{
//	printf("请输入要排查的坐标:>");
//	scanf("%d %d", &x, &y);
//	//判断坐标的有效性
//	if (x >= 1 && x <= row && y >= 1 && y <= col)
//	{
//		//判断是否是雷
//		if (show[x][y] == '*')
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("很遗憾，你踩到雷了\n");
//				DisplayBoard(mine, row, col);
//				break;
//			}
//			else
//			{
//				int count = GetMineCount(mine, x, y);
//				show[x][y] = count + '0';
//				DisplayBoard(show, row, col);
//				win++;
//			}
//		}
//		else
//		{
//			printf("该坐标已经排查过，请重新输入\n");
//		}
//	}
//	else
//	{
//		printf("坐标无效，请重新输入\n");
//	 }
//	}
//	if(win == row * col - EASY_COUNT)
//	{
//		printf("恭喜你，排查成功\n");
//		DisplayBoard(mine, row, col);
//	}
//}
//

#define _CRT_SECURE_NO_WARNINGS 1
#include "minesweeper.h"

// ===== ANSI 颜色 =====
#define CLR_RESET   "\033[0m"
#define CLR_GRAY    "\033[90m"   // 未翻开的格子
#define CLR_BLUE    "\033[34m"   // 1
#define CLR_GREEN   "\033[32m"   // 2
#define CLR_RED     "\033[31m"   // 3 / 旗帜
#define CLR_MAGENTA "\033[35m"   // 4
#define CLR_YELLOW  "\033[33m"   // 5+
#define CLR_CYAN    "\033[36m"   // 边框、提示

// 清理输入缓冲区，防止非法输入导致死循环
static void ClearInput(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)          // 原代码误写成 i < 0，循环从未执行
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

// 按数字大小返回经典扫雷配色
static const char* NumColor(char c)
{
	switch (c)
	{
	case '1': return CLR_BLUE;
	case '2': return CLR_GREEN;
	case '3': return CLR_RED;
	case '4': return CLR_MAGENTA;
	default:  return CLR_YELLOW;
	}
}

// 打印玩家视角的棋盘
void DisplayBoard(char show[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("\n");
	printf(CLR_CYAN "  ======== MINESWEEPER ========\n" CLR_RESET);
	printf("    ");
	for (j = 1; j <= col; j++)
		printf(CLR_CYAN "%2d " CLR_RESET, j);   // 列号
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(CLR_CYAN "%2d  " CLR_RESET, i); // 行号
		for (j = 1; j <= col; j++)
		{
			char c = show[i][j];
			if (c == '*')
				printf(CLR_GRAY " ■ " CLR_RESET);        // 未排查
			else if (c == 'F')
				printf(CLR_RED " ⚑ " CLR_RESET);         // 旗帜
			else if (c == '0')
				printf("   ");                          // 空白
			else if (c >= '1' && c <= '8')
				printf("%s %c " CLR_RESET, NumColor(c), c);
			else if (c == '@')
				printf(CLR_RED " ✹ " CLR_RESET);         // 雷（游戏结束时展示）
			else
				printf(" %c ", c);
		}
		printf("\n");
	}
	printf(CLR_CYAN "  ============================\n" CLR_RESET);
}

// 布置雷：跳过首次点击位置，保证首点安全
void SetMine(char mine[ROWS][COLS], int row, int col, int count, int safe_x, int safe_y)
{
	while (count > 0)
	{
		int x = rand() % row + 1;   // 1 ~ row
		int y = rand() % col + 1;   // 1 ~ col
		if ((x == safe_x && y == safe_y) || mine[x][y] == '1')
			continue;
		mine[x][y] = '1';
		count--;
	}
}

// 统计 (x,y) 周围 8 格的雷数
static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]
		- '0' * 8;
}

// 递归展开：翻开 (x,y)，若周围无雷则连锁翻开周围 8 格
static void Expand(char mine[ROWS][COLS], char show[ROWS][COLS],
	int row, int col, int x, int y, int* revealed)
{
	if (x < 1 || x > row || y < 1 || y > col)
		return;
	if (show[x][y] != '*')          // 已翻开或已插旗，跳过
		return;

	int count = GetMineCount(mine, x, y);
	show[x][y] = count + '0';
	(*revealed)++;

	if (count == 0)                 // 空白格，向四周扩散
	{
		int dx = 0, dy = 0;
		for (dx = -1; dx <= 1; dx++)
			for (dy = -1; dy <= 1; dy++)
				if (dx != 0 || dy != 0)
					Expand(mine, show, row, col, x + dx, y + dy, revealed);
	}
}

// 游戏结束时展示所有雷的位置
static void ShowAllMines(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	for (i = 1; i <= row; i++)
		for (j = 1; j <= col; j++)
			if (mine[i][j] == '1' && show[i][j] != 'F')
				show[i][j] = '@';
	DisplayBoard(show, row, col);
}

// 排查雷（游戏主循环）
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int mine_count)
{
	int revealed = 0;                       // 已翻开的非雷格数
	int flags = 0;                          // 已插旗数
	int first_click = 1;                    // 是否首次点击
	int target = row * col - mine_count;    // 胜利需要翻开的格子数
	time_t start = time(NULL);

	while (revealed < target)
	{
		char op = 0;
		int x = 0, y = 0;

		printf("剩余雷数: %d   操作: o 行 列 = 翻开, f 行 列 = 插旗/取消\n", mine_count - flags);
		printf("请输入:> ");

		int ret = scanf(" %c %d %d", &op, &x, &y);
		if (ret == EOF)                     // 输入流结束，直接退出
		{
			printf("\n游戏结束\n");
			return;
		}
		if (ret != 3)                       // 格式错误（如输入了字母）
		{
			printf("输入格式错误，请重新输入\n");
			ClearInput();
			continue;
		}
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("坐标超出范围，请重新输入\n");
			continue;
		}

		if (op == 'f' || op == 'F')         // 插旗 / 取消旗
		{
			if (show[x][y] == '*')
			{
				show[x][y] = 'F';
				flags++;
			}
			else if (show[x][y] == 'F')
			{
				show[x][y] = '*';
				flags--;
			}
			else
			{
				printf("该格子已翻开，无法插旗\n");
				continue;
			}
			DisplayBoard(show, row, col);
		}
		else if (op == 'o' || op == 'O')    // 翻开
		{
			if (show[x][y] == 'F')
			{
				printf("该格子已插旗，先取消旗帜再翻开\n");
				continue;
			}
			if (show[x][y] != '*')
			{
				printf("该坐标已经排查过，请重新输入\n");
				continue;
			}

			if (first_click)                // 首次点击后才布雷，保证不踩雷
			{
				SetMine(mine, row, col, mine_count, x, y);
				first_click = 0;
			}

			if (mine[x][y] == '1')
			{
				printf("\n很遗憾，你踩到雷了！\n");
				ShowAllMines(mine, show, row, col);
				printf("本局用时: %ld 秒\n", (long)(time(NULL) - start));
				return;
			}

			Expand(mine, show, row, col, x, y, &revealed);
			DisplayBoard(show, row, col);
		}
		else
		{
			printf("未知操作，请输入 o 或 f\n");
		}
	}

	printf("\n恭喜你，排查成功！\n");
	ShowAllMines(mine, show, row, col);
	printf("本局用时: %ld 秒\n", (long)(time(NULL) - start));
}