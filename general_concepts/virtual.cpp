#include <iostream>

using namespace std;

/*
    Virtual functions are member fucntions whose behavior can be overriden in derived classes. 

    Virtual functions offer the advantage that if a derived class is handled using a pointer or reference to
    the base class, a call to an overriden virtual function invokes the behavior in the derived class. 
    This type of function calling is known as virtual function call/virtual call.

    Virtual function calls don't work if the function is selected using qualified name lookup AKA using the
    scope resolution operator AKA ::
*/

// struct Base{
//     virtual void f(){
//         cout << "I'm a base function!\n";
//     }
// };

// struct Derived: Base{
//     void f(){
//         cout << "I'm a derived function! I'm special!\n";
//     }
// };

class Base{
    public:
        virtual void f(){
            cout << "I'm a base function!\n";
        }
};

class Derived: public Base{
    void f(){
        cout << "I'm a derived function! I'm special!\n";
    }
};

int main(){
    Base b;
    Derived d;

    // Virtual function call through reference
    Base& br = b; // The type of br is a Base& and it's a reference to a Base type object
    Base& dr = d; // The type of dr is a Base& and it's a reference to a Derived type object

    br.f(); // Executes Base::f()
    dr.f(); // The type of dr is Base&, but as it's referring to a Derived type object, it executes Derived::f()

    // Virtual function call through pointers
    Base* bp = &b; // The type of bp is a Base* and it's a pointer to a Base type object
    Base* dp = &d; // The type of dp is a Base* and it's a pointer to a Derived type object

    bp->f(); // Executes Base::f()
    dp->f(); // The type of dr is Base*, but as it's pointing to a Derived type object, it executes Derived::f()

    // These are non-virtual function calls, so they call the exact function they're accessing
    br.Base::f(); // Executes Base::f()
    dr.Base::f(); // Executes Base::f()

    return 0;
}