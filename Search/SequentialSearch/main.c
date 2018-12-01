#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // ��������ݶ���Ĭ��Ϊint����

int SequentialSearch(ElementType arr[], int N);    // ����������ǰ������������

int main()
{
    int N = 8;    // 8��Ԫ��

    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // �±�0Ϊ�ڱ�

    arr[0] = 45;
    printf("%d\n", SequentialSearch(arr, N));

    return 0;
}

int SequentialSearch(ElementType arr[], int N)
{
    int i = N;

    while(arr[i] != arr[0]) i--;

    return i;    // ����0�����ʧ��
}
