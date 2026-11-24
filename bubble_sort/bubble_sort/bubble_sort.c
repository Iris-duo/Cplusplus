#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Swap(int* pa, int* pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void bubble_sort(int arr[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        int flag = 1; //假设已经有序
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break; //有序，提前结束！
        }
    }
}

int main()
{
    int a[] = { 1,3,2,5,4 };
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
