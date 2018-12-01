#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // 处理的数据对象默认为int类型

void Swap(ElementType *E1, ElementType *E2);
void BubbleSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8个元素

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // 下标0为哨兵
    //ElementType arr[8+1] = {0, 1, 2, 3, 4, 5, 6, 7, 8};    // 检验是否优化了冒泡排序

    Print(arr, N);    // 初始序列

    BubbleSort(arr, N);
    Print(arr, N);    // 冒泡排序完的序列 从小到大

    return 0;
}

void Swap(ElementType *E1, ElementType *E2)
{
    // 地址传递 值互换
    ElementType temp;
    temp = *E1;
    *E1 = *E2;
    *E2 = temp;
}

void BubbleSort(ElementType arr[], int N)
{
    int i, j;
    int flag = 1;
    for(i = 1; i <= N-1 && flag; ++i){
        for(j = 1; j <= N-i; ++j){
            flag = 0;
            if(arr[j] > arr[j+1]){
                Swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        // Print(arr, N);    // 输出每趟排序的结果
    }
}

void Print(ElementType arr[], int N)
{
    int i;
    for(i = 1; i <= N-1; ++i)
        printf("%d ", arr[i]);
    printf("%d\n", arr[N]);
}
