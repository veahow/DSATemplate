#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // ��������ݶ���Ĭ��Ϊint����

void Swap(ElementType *E1, ElementType *E2);
int Partition(ElementType arr[], int left, int right);
void QSort(ElementType arr[], int left, int right);
void QuickSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8��Ԫ��

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // �±�0Ϊ�ڱ�

    Print(arr, N);    // ��ʼ����

    QuickSort(arr, N);
    Print(arr, N);    // ��������������� ��С����

    return 0;
}

void Swap(ElementType *E1, ElementType *E2)
{
    // ��ַ���� ֵ����
    ElementType temp;
    temp = *E1;
    *E1 = *E2;
    *E2 = temp;
}

int Partition(ElementType arr[], int left, int right)
{
    int pivot;
    pivot = arr[left];    // ���ӱ��һ����¼��Ϊ����

    while(left < right){
        while(left < right && arr[right] >= pivot) right--;
        Swap(&arr[left], &arr[right]);    // ������С�ķ����
        while(left < right && arr[left] <= pivot) left++;
        Swap(&arr[left], &arr[right]);    // �������ķ��ұ�
    }

    // Print(arr, 8);    // ÿ�����

    return left;
}

void QSort(ElementType arr[], int left, int right)
{
    int pivot;
    if(left < right){
        pivot = Partition(arr, left, right);    // ��arrһ��Ϊ�����������ֵpivot

        QSort(arr, left, pivot-1);    // ���ӱ�ݹ�����
        QSort(arr, pivot+1, right);    // ���ӱ�ݹ�����
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
