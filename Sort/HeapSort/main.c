#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // 处理的数据对象默认为int类型

void Swap(ElementType *E1, ElementType *E2);    // 交换函数
void Adjust(ElementType arr[], int i, int N);    // 调整函数 自上向下调整
void HeapSort(ElementType arr[], int N);    // 堆排序函数
void Print(ElementType arr[], int N);    // 打印函数

int main()
{
    int N = 8;    // 8个元素
    //int N = 11;    // 11个元素
    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // 下标0为哨兵
    //ElementType arr[11+1] = {0, 44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 85};    // 下标0为哨兵

    Print(arr, N);    // 初始序列

    HeapSort(arr, N);
    Print(arr, N);    // 堆排序后的序列

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

void Adjust(ElementType arr[], int i, int N)
{
    int child;
    ElementType temp;

    // 向下过滤结点
    for(temp = arr[i]; 2*i <= N; i = child){
        child = 2*i;    // 左孩子结点

        // 最大堆比较 左孩子结点值小于右孩子结点 孩子结点调整为右孩子 否则不调整
        if(child != N && arr[child] < arr[child+1]) child++;

        if(temp < arr[child]) arr[i] = arr[child];    // 小于孩子结点 将孩子结点值赋值到该结点
        else break;

    }
    arr[i] = temp;    // 此时i为孩子结点 把temp放到当前位置
}

void HeapSort(ElementType arr[], int N)
{
    int i;

    // 最大堆建立
    for(i = N/2; i >= 1; --i)
        Adjust(arr, i, N);

    // 额外空间复杂度为O(1)
    for(i = N; i >= 2; --i){
        Swap(&arr[1], &arr[i]);    // 堆顶元素与最后元素互换

        // 因为其他已经调整好了 只需在i-1个元素的新堆的根节点向下调整即可
        Adjust(arr, 1, i-1);
    }

}

void Print(ElementType arr[], int N)
{
    int i;
    for(i = 1; i <= N-1; ++i)
        printf("%d ", arr[i]);
    printf("%d\n", arr[N]);
}
