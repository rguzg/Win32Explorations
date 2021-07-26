/* 
    Angled brakets (<>) are used when including stuff from the standard library
    Quotations ("") are used to include regular files
*/
#include <iostream>
#include "Calculator.h"
#include "Exceptions.cpp"

/*
    Denote that the scope for the file is the standard library
*/
using namespace std;

// This function clears cin's error flags and clears its buffer
void FixBadInput(){
    cin.clear();
    
    // Ignore all characters until the next new line
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){
    double result = 0.0;

    cout << "This is a Cool Calculator Console Application \n";

    Calculator c;

    while(true){
        double x = NULL;
        double y = NULL;
        char operand = NULL;

        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b \n";

        cin >> x >> operand >> y;
        
        try {
            // This pretty much means that the user entered a non-numeric value for x or y
            if(cin.fail()){
                throw InvalidOperationError();
            }
            
            result = c.Calculate(x,operand,y);
        } catch(exception& e) {
            cout << e.what() << "\n";

            // If c has thrown an error, then its likely that cin is in an error state, so we'll clear its error flags and flush the buffer
            FixBadInput();

            continue;
        }        

        cout << "The result is: " << result << "\n";
    }

    return 0;
}