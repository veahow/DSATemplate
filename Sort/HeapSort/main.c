#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    // ��������ݶ���Ĭ��Ϊint����

void Swap(ElementType *E1, ElementType *E2);    // ��������
void Adjust(ElementType arr[], int i, int N);    // �������� �������µ���
void HeapSort(ElementType arr[], int N);    // ��������
void Print(ElementType arr[], int N);    // ��ӡ����

int main()
{
    int N = 8;    // 8��Ԫ��
    //int N = 11;    // 11��Ԫ��
    ElementType arr[8+1] = {0, 99, 66, 45, 33, 37, 10, 22, 13};    // �±�0Ϊ�ڱ�
    //ElementType arr[11+1] = {0, 44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 85};    // �±�0Ϊ�ڱ�

    Print(arr, N);    // ��ʼ����

    HeapSort(arr, N);
    Print(arr, N);    // ������������

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

void Adjust(ElementType arr[], int i, int N)
{
    int child;
    ElementType temp;

    // ���¹��˽��
    for(temp = arr[i]; 2*i <= N; i = child){
        child = 2*i;    // ���ӽ��

        // ���ѱȽ� ���ӽ��ֵС���Һ��ӽ�� ���ӽ�����Ϊ�Һ��� ���򲻵���
        if(child != N && arr[child] < arr[child+1]) child++;

        if(temp < arr[child]) arr[i] = arr[child];    // С�ں��ӽ�� �����ӽ��ֵ��ֵ���ý��
        else break;

    }
    arr[i] = temp;    // ��ʱiΪ���ӽ�� ��temp�ŵ���ǰλ��
}

void HeapSort(ElementType arr[], int N)
{
    int i;

    // ���ѽ���
    for(i = N/2; i >= 1; --i)
        Adjust(arr, i, N);

    // ����ռ临�Ӷ�ΪO(1)
    for(i = N; i >= 2; --i){
        Swap(&arr[1], &arr[i]);    // �Ѷ�Ԫ�������Ԫ�ػ���

        // ��Ϊ�����Ѿ��������� ֻ����i-1��Ԫ�ص��¶ѵĸ��ڵ����µ�������
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
