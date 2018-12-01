#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // ��������ݶ���Ĭ��Ϊint����

void InsertionSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8��Ԫ��

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // �±�0Ϊ�ڱ�

    Print(arr, N);    // ��ʼ����

    InsertionSort(arr, N);
    Print(arr, N);    // ֱ�Ӳ�������������� ��С����

    return 0;
}

void InsertionSort(ElementType arr[], int N)
{
    int i, j;
    for(i = 2; i <= N; ++i){
        if(arr[i] < arr[i-1]){
            arr[0] = arr[i];    // �ڱ���Źؼ���ֵ
            for(j = i-1; arr[j] > arr[0]; --j)
                arr[j+1] = arr[j];
            arr[j+1] = arr[0];
            // Print(arr, N);    // ���ÿ������Ľ��
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
