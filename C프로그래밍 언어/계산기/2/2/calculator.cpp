#include "calculator.h"

Calculator::Calculator(double x_val, char op, double y_val) : x(x_val), oper(op), y(y_val), sum(0) {}

void Calculator::performOperation() //��� �κ�
{
    switch (oper)//switch�� ���
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
            std::cout << "0���� ���� �� �����ϴ�" << std::endl;
        break;
    default:
        std::cout << "��ȿ���� ���� ������ �Դϴ�." << std::endl;
        return;
    }
}

void Calculator::printResult()//����� ���
{
    std::cout << "Result: " << sum << std::endl;
}

void Calculator::clear() //c�� �Է��Ͽ��� ��� �ʱ�ȭ
{
    sum = 0;
}

double Calculator::getResult() const //��������� �̾ ����ϱ� ���� ���
{
    return sum;
}