#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // 处理的数据对象默认为int类型

int SequentialSearch(ElementType arr[], int N);    // 二分搜索的前提是数组有序

int main()
{
    int N = 8;    // 8个元素

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // 下标0为哨兵

    arr[0] = 45;
    printf("%d\n", SequentialSearch(arr, N));

    return 0;
}

int SequentialSearch(ElementType arr[], int N)
{
    int i = N;

    while(arr[i] != arr[0]) i--;

    return i;    // 返回0则查找失败
}
