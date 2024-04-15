#include "calculator.h"

Calculator::Calculator(double x_val, char op, double y_val) : x(x_val), oper(op), y(y_val), sum(0) {}

void Calculator::performOperation() //계산 부분
{
    switch (oper)//switch문 사용
    {
    case '+':
        sum = x + y;
        break;
    case '-':
        sum = x - y;
        break;
    case '*':
        sum = x * y;
        break;
    case '/':
        if (y != 0)
            sum = x / y;
        else
            std::cout << "0으로 나눌 수 없습니다" << std::endl;
        break;
    default:
        std::cout << "유효하지 않은 연산자 입니다." << std::endl;
        return;
    }
}

void Calculator::printResult()//결과값 출력
{
    std::cout << "Result: " << sum << std::endl;
}

void Calculator::clear() //c를 입력하였을 경우 초기화
{
    sum = 0;
}

double Calculator::getResult() const //결과값에서 이어서 계산하기 위해 사용
{
    return sum;
}