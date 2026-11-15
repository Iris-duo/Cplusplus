#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//菜单
void meun()
{
	printf("\n***************************\n");
	printf("\n*******    1.PLAY   *******\n");
	printf("\n*******    0.EXIT   *******\n");
	printf("\n***************************\n");
}

void game() {
	//1.需要存放布置好的雷的信息,存放排查出的雷的信息，需要两个二维数组
	//2.排查坐标的时候，为了防止坐标越界，行和列都增加2行

	char mine[ROWS][COLS] = { 0 };//mine-雷，布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//排查出的雷的信息

	//初始化棋牌
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);

	//布置雷
	Setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//排查雷
	Findmine(mine, show, ROW, COL);

}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do
	{
		meun();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏。\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
