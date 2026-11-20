#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
//	int a = 0;
//	int* p = &a;	//p是一个变量(存放指针的变量)，是一块空间

	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(char*));


	return 0;
}