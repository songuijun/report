#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define data_size 10

int main(void)
{
	int data[data_size];
	int temp;
	printf("데이터값을 입력하여 주세요: ");
	for (int i = 0; i < data_size; i++)
	{
		int num1 = 0;
		scanf(" %d ", &num1);
		data[i] = num1;
	}

	printf(" \n 현재 데이터 입니다:\t");
	for (int i = 0; i < data_size; i++)
	{
		printf("%d \t", data[i]);
	}

	for (int i = 0; i < data_size; i++)
	{
		for (int j = 0; j < data_size; j++)
		{
			if (data[i] < data[j])
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}

	printf(" \n 정렬된 데이터 입니다:\t");

	for (int i = 0; i < data_size; i++)
	{
		printf("%d \t", data[i]);
	}
}