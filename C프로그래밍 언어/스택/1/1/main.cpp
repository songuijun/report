#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_STACK_SIZE 5 //�迭�� ũ�� ����

int stack[MAX_STACK_SIZE];//������ ũ�⿡ ���� �迭 ����
int top = -1;

bool IsEmpty()
{
    return top < 0;
}
bool IsFull() 
{
    return top >= MAX_STACK_SIZE - 1;
}
int nowstack()//���� ������ ���¸� ����ϴ� �Լ�
{
    printf("=================================\n\n");
    for (int i = top; i >= 0; i--)//���� for���� ������ ���Ͽ� ���ÿ� ���� �������� �Էµ� ���ں��� ���
    {
        printf("%d \n", stack[i]);
    }
    printf("\n\n=================================\n\n");
    return 1;
}
void push(int value)//���ÿ� ���ڸ� �Է��ϴ� �Լ�
{
    if (IsFull())//������ ����á���ÿ� ����ϵ��� if������
    {
        printf("������ ���� á���ϴ�.\n");
        nowstack();
    }
    else//������ �������� �ʾ������ ���ڸ� �Է��ϰ� ���� ���� ���
    {
        stack[++top] = value;
        nowstack();
    }
}

int pop()//������ ���� ����
{
    if (IsEmpty())//������ ����������
    {
        printf("������ ������ϴ�.\n");
        nowstack();
        return -1;
    }
    else//���ÿ� ���� ����, ������ ���û�Ȳ ���
    {
        int poppedValue = stack[top--];
        nowstack();
        return poppedValue;
    }
}

void askprogram()//�Է��ϰ��� �ϴ� ���� �Է¹޴� ���α׷�
{
    int number;
    printf("�Է��ϰ��� �ϴ� ���� �Է��Ͽ� �ּ���: ");
    scanf("%d", &number);
    push(number);//�Է¹������� push
}

void startProgram()//�������α׷� while���� ���Ͽ� ���� �ݺ�
{
    char choice;

    while (1)
    {
        printf("��ɾ �Է��Ͽ� �ּ���: ");
        scanf(" %c", &choice);
        printf("\n");

        if (choice == 'q' || choice == 'Q')
        {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else if (choice == 'u' || choice == 'U')
        {
            askprogram();
        }
        else if (choice == 'o' || choice == 'O')
        {
            pop();
        }
        else
        {
            printf("�������� �ʴ� ��ɾ� �Դϴ� �ٽ� �Է��Ͽ� �ּ���.\n\n");
        }
    }
}

int main()
{
    printf("���α׷��� �����Ͻðڽ��ϱ�? (q: ����, u: �� �߰�, o: �� ����)\n ");
    startProgram();

    return 0;
}