//#define _CRT_SECURE_NO_WARNINGS 1
//#include"minesweeper.h"
//
//void menu()
//{
//	printf("====================\n");
//	printf("====1. Start Game===\n");
//	printf("==== 0. Exit   =====\n");
//	printf("====================\n");
//
//}
//
//void game()
//{
//	//完成扫雷游戏  
//	char mine[ROWS][COLS] = { 0 };	//数组全部初始化为0
//	char show[ROWS][COLS] = { 0 };	//数组全部初始化为*
//
//	//初始化棋盘
//	//mine数组中存放布置好的雷的信息
//	InitBoard(mine, ROWS, COLS,'0');	
//
//	//show数组中存放玩家看到的棋盘信息
//	InitBoard(show, ROWS, COLS,'*');
//
//	//打印棋盘
//	//DisplayBoard(mine,ROW,COL);
//	//DisplayBoard(show,ROW, COL);
//
//	//布置雷
//	//在9*9的棋盘中随机布置10个雷
//	SetMine(mine,ROW,COL);
//	//DisplayBoard(mine,ROW,COL);
//
//	//打印棋盘
//	DisplayBoard(show,ROW, COL);
//
//	//排查雷
//	FindMine(mine,show,ROW,COL);
//}
//
//void test()
//{
//	int input = 0;	
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//				printf("开始游戏\n");
//				game();	
//				break;
//			case 0:	
//				printf("退出游戏\n");
//				break;
//			default:
//				printf("选择错误，请重新选择\n");
//				break;	
//		}
//	} while (input);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include "minesweeper.h"

// Windows 下开启 ANSI 颜色支持（Linux / macOS 终端默认支持）
#ifdef _WIN32
#include <windows.h>
static void EnableColor(void)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hOut, &mode);
	SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
static void EnableColor(void) {}
#endif

static void menu(void)
{
	printf("====================\n");
	printf("==== 1. Start Game =\n");
	printf("==== 0. Exit       =\n");
	printf("====================\n");
}

// 清空一行非法输入（遇到 EOF 也能安全退出）
static void ClearLine(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

static void game(void)
{
	char mine[ROWS][COLS] = { 0 };  // 雷区：'1' 有雷，'0' 无雷
	char show[ROWS][COLS] = { 0 };  // 玩家视角：'*' 未排查，'F' 旗帜

	int row = 0, col = 0, mine_count = 0;
	int level = 0;

	printf("请选择难度：1. 简单 9x9 (10雷)   2. 中等 16x16 (40雷)\n");
	printf("请选择:> ");
	if (scanf("%d", &level) != 1)
	{
		level = 1;
		ClearLine();  // 清空非法输入
	}

	if (level == 2)
	{
		row = 16; col = 16; mine_count = 40;
	}
	else
	{
		row = 9; col = 9; mine_count = 10;
	}

	// 初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	// 打印初始棋盘（雷在首次点击后才布置，保证首点安全）
	DisplayBoard(show, row, col);

	// 排查雷
	FindMine(mine, show, row, col, mine_count);
}

static void test(void)
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:> ");
		int ret = scanf("%d", &input);
		if (ret == EOF)    // 输入流结束，直接退出
			break;
		if (ret != 1)
		{
			printf("输入错误，请重新选择\n");
			ClearLine();
			input = -1;
			continue;
		}
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main(void)
{
	EnableColor();
	test();
	return 0;
}