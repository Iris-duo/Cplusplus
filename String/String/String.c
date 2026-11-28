#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main()
{
	char arr[] = "I Am a Student.";
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	while (arr[i] != '\0')
	{
		if (islower(arr[i]))
		{
			arr[i] -= 32;
		}
		i++;
	}

	for (int i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}

	return 0;
}