#define _CRT_SECURE_NO_WARNINGS 1

#include"minesweeper.h"

//打印菜单函数
void menu()
{
	printf("====================\n");
	printf("==== 1. Start Game =\n");
	printf("==== 0. Exit       =\n");
	printf("====================\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');   // mine 棋盘全填 '0'（暂时没雷）
	InitBoard(show, ROWS, COLS, '*');   // show 棋盘全填 '*'（都没翻开）

	//布置雷
	SetMine(mine, 9, 9, 10);            // 在 mine �

	//打印棋盘
	DisplayBoard(show, 9, 9);           // 先按 9×9 打印
	//DisplayBoard(mine, 9, 9);           // 先按 9×9 打印
	FindMine(mine, show, 9, 9, 10);       // 开始排雷

}

int main()
{

	int input = 0;
	srand((unsigned int)time(NULL)); // 设置随机数种子
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请开始游戏\n");
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
	return 0;
}