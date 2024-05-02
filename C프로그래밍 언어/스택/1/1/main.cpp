#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_STACK_SIZE 5 //배열의 크기 제한

int stack[MAX_STACK_SIZE];//제한한 크기에 따른 배열 생성
int top = -1;

bool IsEmpty()
{
    return top < 0;
}
bool IsFull() 
{
    return top >= MAX_STACK_SIZE - 1;
}
int nowstack()//현재 스택의 상태를 출력하는 함수
{
    printf("=================================\n\n");
    for (int i = top; i >= 0; i--)//다음 for문의 조건을 통하여 스택에 가장 마지막에 입력된 숫자부터 출력
    {
        printf("%d \n", stack[i]);
    }
    printf("\n\n=================================\n\n");
    return 1;
}
void push(int value)//스택에 숫자를 입력하는 함수
{
    if (IsFull())//스택이 가득찼을시에 출력하도록 if문설정
    {
        printf("스택이 가득 찼습니다.\n");
        nowstack();
    }
    else//스택이 가득차지 않았을경우 숫자를 입력하고 현재 스택 출력
    {
        stack[++top] = value;
        nowstack();
    }
}

int pop()//스택의 숫자 제거
{
    if (IsEmpty())//스택이 비어있을경우
    {
        printf("스택이 비었습니다.\n");
        nowstack();
        return -1;
    }
    else//스택에 숫자 제거, 제거후 스택상황 출력
    {
        int poppedValue = stack[top--];
        nowstack();
        return poppedValue;
    }
}

void askprogram()//입력하고자 하는 값을 입력받는 프로그램
{
    int number;
    printf("입력하고자 하는 값을 입력하여 주세요: ");
    scanf("%d", &number);
    push(number);//입력받은값을 push
}

void startProgram()//시작프로그램 while문을 통하여 무한 반복
{
    char choice;

    while (1)
    {
        printf("명령어를 입력하여 주세요: ");
        scanf(" %c", &choice);
        printf("\n");

        if (choice == 'q' || choice == 'Q')
        {
            printf("프로그램을 종료합니다.\n");
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
            printf("존재하지 않는 명령어 입니다 다시 입력하여 주세요.\n\n");
        }
    }
}

int main()
{
    printf("프로그램을 시작하시겠습니까? (q: 종료, u: 값 추가, o: 값 제거)\n ");
    startProgram();

    return 0;
}