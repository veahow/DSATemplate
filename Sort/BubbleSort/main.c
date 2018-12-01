#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // ��������ݶ���Ĭ��Ϊint����

void Swap(ElementType *E1, ElementType *E2);
void BubbleSort(ElementType arr[], int N);
void Print(ElementType arr[], int N);

int main()
{
    int N = 8;    // 8��Ԫ��

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // �±�0Ϊ�ڱ�
    //ElementType arr[8+1] = {0, 1, 2, 3, 4, 5, 6, 7, 8};    // �����Ƿ��Ż���ð������

    Print(arr, N);    // ��ʼ����

    BubbleSort(arr, N);
    Print(arr, N);    // ð������������� ��С����

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
