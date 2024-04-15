#include <math.h>
#include <iostream>

class Calculator //class �Լ� 
{
private:
    double x;
    char oper;
    double y;
    double sum;

public:
    Calculator(double x_val, char op, double y_val);
    void performOperation();
    void printResult();
    void clear();
    double getResult() const;
};

