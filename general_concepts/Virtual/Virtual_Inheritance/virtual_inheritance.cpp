/*
    A virtual function can be overriden by another function in a class that inherits from the base class if
    said function has the same:
        - name
        - parameter type list (but not return type)
        - cv-qualifiers (constant or volatile qualifiers)
        - ref-qualifiers (too complex to get into right now, 
        but basically it refers to if the function has the & qualifier or the && qualifier)

    Functions that override virtual functions are also virtual.
    A function doesn't need to be visible to be overriden
*/

#include <iostream>

using namespace std;

class B{
    virtual void do_f(){
        cout << "I'm doing f!\n";
    }

    public:
        void f() {
            do_f();
        }
};

class D: public B{
    void do_f() {
        cout << "I have overriden the original function, muahahaha!!\n";
    }
};

class E: public D{
    void do_f(){
        cout << "Override Squared!\n";
    }
};

class H: public D{
    void do_f(int a){
        cout << "I'm not overriding because I changed the parameters, look here's an int! " << a << "\n";
    }
};

int main(){
    D d;
    B* bp = &d;
    bp->f(); // Internally calls D::do_f(). This is because B::do_f has been overriden. Notice how it was able to be overriden even though B::do_f is private

    // Notice also how as bp is an object of type B* that points to a D object, D::do_f() is executed instead of B::do_f()

    // As this is an instance of B, B::f() is executed
    B b;
    b.f();

    // Overriding D::do_f. We can do this because D::do_f is also virtual!
    E e;

    /* 
        Notice how even though the E class doesn't have an f() member function, the code still works. This is because we're using 
        public inhertiance
    */
    e.f(); 

    B* ep = &e;
    ep->f();

    // Calls to H::do_f() don't execute H::do_f(), but rather D::do_f(). This is because as the parameters from H::do_f() and D::do_f() are different the function isn't being overriden. 
    H h;
    h.f();

    B* hp = &h;
    hp->f();

    return 0;
}