#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define data_size 10

void insertion_sort(int data[]) 
{
    int temp,j;

    for (int i = 1; i < data_size; i++)
    {
        temp = data[i];
        for (j = i - 1; j >= 0 && data[j] > temp; j--) 
        {
            data[j + 1] = data[j];
        }

        data[j + 1] = temp;
    }
}

void main() 
{
    int data[data_size];
    int temp;
    printf("�����Ͱ��� �Է��Ͽ� �ּ���: ");
    for (int i = 0; i < data_size; i++)
    {
        int num1 = 0;
        scanf(" %d ", &num1);
        data[i] = num1;
    }

    printf(" \n ���� ������ �Դϴ�:\t");
    for (int i = 0; i < data_size; i++)
    {
        printf("%d \t", data[i]);
    }

    insertion_sort(data);

    printf(" \n ���ĵ� ������ �Դϴ�:\t");

    for (int i = 0; i < data_size; i++)
    {
        printf("%d \t", data[i]);
    }
}