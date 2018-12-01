#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // 处理的数据对象默认为int类型

void InsertionSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8个元素

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // 下标0为哨兵

    Print(arr, N);    // 初始序列

    InsertionSort(arr, N);
    Print(arr, N);    // 直接插入排序完的序列 从小到大

    return 0;
}

void InsertionSort(ElementType arr[], int N)
{
    int i, j;
    for(i = 2; i <= N; ++i){
        if(arr[i] < arr[i-1]){
            arr[0] = arr[i];    // 哨兵存放关键字值
            for(j = i-1; arr[j] > arr[0]; --j)
                arr[j+1] = arr[j];
            arr[j+1] = arr[0];
            // Print(arr, N);    // 输出每趟排序的结果
        }
    }
}

void Print(ElementType arr[], int N)
{
    int i;
    for(i = 1; i <= N-1; ++i)
        printf("%d ", arr[i]);
    printf("%d\n", arr[N]);
}
