#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
//	int a = 0;
//	int* p = &a;	//p是一个变量(存放指针的变量)，是一块空间
	
	//指针变量的大小
	/*printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(char*));*/

	//int a = 0x11223344;
	////int* p = &a;
	//char* p = &a;

	//*p = 0;

	//const int a = 10;
	////a = 20;	//err
	//int* p = &a;
	//*p = 20;	//a =20

	//// arr[a] = { };
	//printf("%d\n",a);


	/*int a = 10;
	int b = 20;

	int const * p = &a;
	p = &b;
	*p = 90;*/
	//int* const p = &a;


	int m = 10;		//m是爸爸，爸爸自己只有10块
	int n = 100;	//n是妈妈，妈妈掌管财政大权有100块
	int* p = &m;	//p是宝宝，一般和爸爸一起花钱

 	return 0;
}