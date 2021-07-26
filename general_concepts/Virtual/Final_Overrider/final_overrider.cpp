/*
    For every virtual function, there's a final overrider. The final overrider is what is executed when the
    virtual function call is made.

    The final overrider can be either the virtual function in the base class or another function declared in
    a derived class.
*/

#include <iostream>

using namespace std;

struct A {virtual void f() {cout << "I'm a base function!\n";} };

// B::f overrides A::f in B
struct B: A {void f() {cout << "I'm overriding A!\n";} };

/*
    The C and D structs need to use virtual inheritance, because E inherits from both of them.

    As both C and D inherit from B, when using an object that inherits from C and D, it'd be ambiguous
    as to which instance of B to use for inheritance.

    The virtual keyword solves this problem, also known as the Dreadful Diamond of Derivation.

    The way this problem is solved is interesting but we won't get into it here. You can check out more here:
    https://www.cprogramming.com/tutorial/virtual_inheritance.html
*/

// C::f overrides B::f in C
struct C: virtual B {void f() {cout << "I'm overriding B!\n";} };

// D doesn't introduce an override, so B::f is the final overrider in D
struct D: virtual B {};

// E doesn't introduce an override, so C::f is the final overrider in E
struct E: C, D { 
    using A::f; // Not a function declaration, just makes A::f visible
};

// If a function has more than one final overrider, the program is ill-formed and it'll not compile, because
// the function that should be used is ambiguous

struct CrustyStruct1: virtual A{void f() {cout << "I'm overriding A!\n";} };

struct CrustyStruct2: virtual A{void f() {cout << "I'm overriding A!\n";} };

/*
    struct Error: CrustyStruct1, CrustyStruct2{
        // A call to Error.f() is ambiguous here
    };
*/

struct Okay: CrustyStruct1, CrustyStruct2{
    // This now the final overrider for A::f, so a call to Okay.f() is no longer ambiguous
    void f() {cout << "I'm not ambiguous! (or Among Us) \n";}
};

struct VB1: virtual A{}; // Doesn't declare an overrider

struct Da: VB1, CrustyStruct2{
    // The final overrider in here is CrustryStruct2::f
};

int main() {
    E e;
    e.f(); // Virtual call calls C::f, the final overrider in e
    e.E::f(); // Non-virtual call calls A::f, which is visible in E

    CrustyStruct1 c1;
    c1.f(); // Virtual call calls c1::f, the final overrider in CrustyStruct1

    CrustyStruct2 c2;
    c2.f(); // Virtual call calls c2::f, the final overrider in CrustyStruct2

    Okay ok;
    ok.f(); // Virtual call calls ok::f, the final overrider in Okay

    VB1 vb;
    vb.f(); // Virtual call calls A::f, the final overrider in VB1

    Da d;
    d.f(); // Virtual call calls VB2::f, the final overrider in Da

    A a;
    a.f(); // Virtual call calls a::f, the final overrider in A

    return 0;
}