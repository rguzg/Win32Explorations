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

    Calculator c;

    while(true){
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b \n";

        cin >> x >> operand >> y;
        
        try {
            result = c.Calculate(x,operand,y);
        } catch(const std::runtime_error& e) {
            cout << "Cannot divide by zero. Please try again \n";
            continue;
        }        

        cout << "The result is: " << result << "\n";
    }

    return 0;
}