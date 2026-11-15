#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[10] = { 0 };
	int a = 5;
	int b = 1;
	
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		arr[i] = i;
		printf("%d\n", i);
	}	

	return 0;
}