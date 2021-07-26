#include <exception>

/* 
    It's necessary to specify public inheritance from std::exception for two reasons:
        - If public inheritance is not specified, the inherited member function what will become private
        and the main function wouldn't be able to access it inside the catch block
        - Public inheritance exposes to the public the relationship between the inherited class and 
        the base class, this means that references and pointers to the inherited class can be used 
        in places where code expects references or pointers to any of its public bases. 
        This makes the line catch(exception& e) work

        https://docs.microsoft.com/en-us/cpp/cpp/const-cpp?view=msvc-160#const-member-functions
        https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
*/
class InvalidOperationError: public std::exception{
    /*
        The second const keyword specifies that the member function is a read-only function, so it can't modify
        any object properties

        It's also necessary to make the function constant because std::exception.what is also a 
        constant function. If the keyword is missing and thus the function isn't overriden, 
        as the catch block is using a reference to exception and not the inheriting class, std::exception.what
        will be executed

        https://en.cppreference.com/w/cpp/language/virtual
    */
    const char* what() const throw(){
        return "An invalid operation was entered";
    }
};

class DivideByZeroError: public std::exception{
    const char* what() const throw(){
        return "Cannot divide by zero";
    }
};