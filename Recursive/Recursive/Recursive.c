#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//
////史上最简单的C语言递归代码
//int main()
//{
//	printf("Hello");
//	main();	//在main函数中调用main函数本身，形成递归
//	return 0;
//}

/*
//Factorial function using recursion
#include<stdio.h>

int Fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Fact(n - 1);
}

int main()
{
	int n = 0;
	printf("请输入要计算的值:> ");
	scanf("%d", &n);
	int ret = Fact(n);
	printf("%d 的阶乘是：%d\n", n, ret);
	return 0;
}
*/

/*
//拆分数字
#include<stdio.h>

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d ", n%10);
}

int main()
{
	int n = 0;
	printf("请输入要拆分的值:> ");	
	while(scanf("%d", &n))
	{
		Print(n);
		printf("\n");
		printf("请输入要拆分的值:> ");
	}
	return 0;
}
*/

/*
#include<stdio.h>
#include<time.h>
int count = 0;

int Fib(int n)
{
	if (n == 3)
		count++;
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}

int main()
{
	int n = 0;
	printf("请输入你想要得到的斐波那契数列的项数:> ");

	while (scanf("%d", &n))
	{

		clock_t start = clock();

		int ret = Fib(n);

		clock_t end = clock();
		double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
		printf("%d 的斐波那契数列是：%d\n", n, ret);
		printf("\n");
		printf("第三位斐波那契数计算的次数 count = %d\n", count);
		printf("\n");
		printf("计算耗时: %f 秒\n", time_taken);
		printf("\n");
		printf("请输入你想要得到的斐波那契数列的项数:> ");
	}
	while (scanf("%d", n))
	{
		int ret = Fib(n);
		printf("%d 的斐波那契数列是：%d\n", n, ret);
		printf("请输入你想要得到的斐波那契数列的项数:> ");
		printf("\n");
	}
return 0;}
*/

#include<stdio.h>
#include<time.h>
int count = 0;

int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n >= 3)
	{
		if (n == 3)
			count++;
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	printf("请输入你想要得到的斐波那契数列的项数:> ");
	while (scanf("%d", &n))
	{
		clock_t start = clock();

		int ret = Fib(n);

		clock_t end = clock();
		double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

		printf("%d 的斐波那契数列是：%d\n", n, ret);
		printf("\n");
		printf("第三位斐波那契数计算的次数 count = %d\n", count);
		printf("\n");
		printf("计算耗时: %f 秒\n", time_taken);
		printf("\n");
		printf("请输入你想要得到的斐波那契数列的项数:> ");


	}

	
	return 0;
}