#include "calculator.h"

int main() 
{
    //변수들
    char choice;
    double x, y, result = 0;
    char oper = '+';
    bool use_previous_result = false;
    //프로그램 시작전 프로그램 소개
    std::cout << "계산기 프로그램" << std::endl;
    do 
    {
        if (!use_previous_result) 
        {
            std::cout << "수식을 입력하여주세요 \t";
            std::cout << "ex) 2 * 4 \n \t\t\t:";
            std::cin >> x >> oper >> y;
        }
        else 
        {
            std::cout << "수식을 입력하세요 (이전 결과 " << result << " 에서 계산): ";
            std::cin >> oper >> y;
            x = result;
        }

        Calculator calc(x, oper, y);
        calc.performOperation();
        result = calc.getResult();
        calc.printResult();

        std::cout << "계속하려면 아무 키나 입력하세요 (C: 초기화, Q: 종료): ";
        std::cin >> choice;

        if (choice == 'C' || choice == 'c')
        {
            result = 0;
            use_previous_result = false;
        }
        else 
        {
            use_previous_result = true;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 'Q' && choice != 'q');

    std::cout << "계산기 프로그램을 종료합니다." << std::endl;

    return 0;
}