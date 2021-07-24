/* 
    Angled brakets (<>) are used when including stuff from the standard library
    Quotations ("") are used to include regular files
*/
#include <iostream>
#include "Calculator.h"

/*
    Denote that the scope for the file is the standard library
*/
using namespace std;

int main(){
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char operand = '+';

    cout << "This is a Cool Calculator Console Application \n";
    cout << "Please enter the operaation to perform. Format: a+b | a-b | a*b | a/b \n";

    Calculator c;

    while(true){
        cin >> x >> operand >> y;
        result = c.Calculate(x,operand,y);
        cout << "The result is: " << result << "\n";
    }

    return 0;
}