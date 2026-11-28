#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//断言
//#define NDEBUG
//#include<assert.h>
//
//int main()
//{
//
//	int n = 0;
//	scanf("%d", &n);
//	printf("n = %d\n", n);
//
//	assert(n > 10);
//
//	return 0;
//}

//编写一个函数，交换两数的值
//void Swap1(int a, int b)
//{
//	int tmp = a;
//	a = b;
//	a = tmp;
//}
//
//void Swap2(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("交换前：a = %d , b = %d\n", a, b);
//
//	//Swap1(a, b);
//	Swap2(&a, &b);
//
//	printf("交换后：a = %d , b = %d\n", a, b);
//
//	return 0;
//}

//数组名的理解
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//
//	printf("arr      = %p\n", arr);
//	printf("arr + 1  = %p\n", arr + 1);
//	printf("\n");
//
//	printf("&arr[0]	    = %p\n", &arr[0]);
//	printf("&arr[0] + 1 = %p\n", &arr[0] + 1);
//	printf("\n");
//
//	printf("&arr	 = %p\n", &arr);
//	printf("&arr + 1 = %p\n", &arr + 1);
//
//	return 0;
//}

//使用指针
//int main()
//{
//	int arr[10] = { 0 };
//
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//赋值
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", p + i);
//	}
//	//打印
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//
//	return 0;
//}

//一维数组传参

//void Print(int arr[10],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//void Print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Print(arr,sz);	//数组名就是数组元素的首元素的地址
//	return 0;
//}

//Bubble_sort

//void Swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				Swap(&arr[j], &arr[j + 1]);
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;	//有序，提前结束
//		}
//	}
//}
//
//void Print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5 ,4, 3, 2 ,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("Bubble_sort前：");
//	Print(arr, sz);
//
//	bubble_sort(arr, sz);
//	
//	printf("\nBubble_sort后：");
//	Print(arr, sz);
//	return 0;
//}

//二级指针

//int main()
//{
//	int a = 10;
//	int* P = &a;
//	int** Pp = &P;
//
//	printf("&a  = %p\n", &a);
//	printf("*Pp = %p\n", *Pp);
//	printf("**p = %d\n", **Pp);
//
//	
//
//	return 0;
//}

//用指针模拟二维数组

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };

	int* arr[] = { arr1,arr2,arr3 };

	//打印
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}