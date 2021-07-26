#include <stdexcept>
#include "Calculator.h"
#include "Exceptions.cpp"

double Calculator::Calculate(double x, char operand, double y){
    switch(operand){
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if(y == 0){
                throw DivideByZeroError();
            }

            return x / y;
        default:
            throw InvalidOperationError();
    }
}