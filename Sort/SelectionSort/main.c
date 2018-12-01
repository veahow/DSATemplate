#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // ��������ݶ���Ĭ��Ϊint����

void Swap(ElementType *E1, ElementType *E2);
void SelectionSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8��Ԫ��

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // �±�0Ϊ�ڱ�

    Print(arr, N);    // ��ʼ����

    SelectionSort(arr, N);
    Print(arr, N);    // ð������������� ��С����

    return 0;
}

void Swap(ElementType *E1, ElementType *E2)
{
    ElementType temp;
    temp = *E1;
    *E1 = *E2;
    *E2 = temp;
}

void SelectionSort(ElementType arr[], int N)
{
    int i, j, min;

    for(i = 1; i <= N-1; ++i){
        min = i;

        for(j = i+1; j <= N; ++j)
            if(arr[min] > arr[j]) min = j;

        if(min != i) Swap(&arr[i], &arr[min]);
        // Print(arr, N);    // ���ÿ������Ľ��
    }

}

void Print(ElementType arr[], int N)
{
    int i;
    for(i = 1; i <= N-1; ++i)
        printf("%d ", arr[i]);
    printf("%d\n", arr[N]);
}
