#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define NDEBUG
#include<assert.h>

int main()
{
	int n = 2;
	scanf("%d", &n);
	assert(n > 3);
	printf("%d ", n);

	return 0;
}