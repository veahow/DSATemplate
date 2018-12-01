#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // 处理的数据对象默认为int类型

void Swap(ElementType *E1, ElementType *E2);
int Partition(ElementType arr[], int left, int right);
void QSort(ElementType arr[], int left, int right);
void QuickSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8个元素

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // 下标0为哨兵

    Print(arr, N);    // 初始序列

    QuickSort(arr, N);
    Print(arr, N);    // 快速排序完的序列 从小到大

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

int Partition(ElementType arr[], int left, int right)
{
    int pivot;
    pivot = arr[left];    // 用子表第一个记录作为枢轴

    while(left < right){
        while(left < right && arr[right] >= pivot) right--;
        Swap(&arr[left], &arr[right]);    // 比枢轴小的放左边
        while(left < right && arr[left] <= pivot) left++;
        Swap(&arr[left], &arr[right]);    // 比枢轴大的放右边
    }

    // Print(arr, 8);    // 每趟输出

    return left;
}

void QSort(ElementType arr[], int left, int right)
{
    int pivot;
    if(left < right){
        pivot = Partition(arr, left, right);    // 将arr一分为二并算出枢轴值pivot

        QSort(arr, left, pivot-1);    // 左子表递归排序
        QSort(arr, pivot+1, right);    // 右子表递归排序
    }

}

void QuickSort(ElementType arr[], int N)
{
    QSort(arr, 1, N);
}

void Print(ElementType arr[], int N)
{
    int i;
    for(i = 1; i <= N-1; ++i)
        printf("%d ", arr[i]);
    printf("%d\n", arr[N]);
}
