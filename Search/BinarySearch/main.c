#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // 处理的数据对象默认为int类型

int BinarySearch(ElementType arr[], int N);    // 二分搜索的前提是数组有序

int main()
{
    int N = 8;    // 8个元素

    ElementType arr[8+1] = {0, 1, 2, 3, 4, 5, 6, 7, 8};    // 下标0为哨兵

    arr[0] = 5;
    printf("%d\n", BinarySearch(arr, N));

    return 0;
}

int BinarySearch(ElementType arr[], int N)
{
    int left = 1, right = N;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] > arr[0]) right = mid-1;
        if(arr[mid] < arr[0]) left = mid+1;
        if(arr[mid] == arr[0]) return mid;
    }

    return 0;    // 查找失败
}
