#include "Calculator.h"

double Calculator::Calculate(double x, char operand, double y){
    switch(operand){
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            return 0.0;
    }
}