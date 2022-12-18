// Polymorphism (many forms)

/*
    Carbon -> Graphite, Diamond, CO2

    Types of Polymorphism :
    - Compile Time
        • Function Overloading
        • Operator Overloading
    - Run Time
        • Virtual Functions

    What is Function Overloading?
    - when there are different function with same name but different no of argument or different type of argument.

    What is Operator Overloading?
    eg. addition of complex numbers
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// Compile time polymorphism
class Test {
    public:
        // function overloading
        void foo() {
            cout<<"foo()"<<endl;
        }
        void foo(int x) {
            cout<<"foo(int x)"<<endl;
        }
        void foo(double x) {
            cout<<"foo(double x)"<<endl;
        }
};

class Complex {
    int real, imag;
    public:
        Complex(int r=0, int i=0) {
            this->real = r;
            this->imag = i;
        }

        // Operator Overloading
        // Complex operator+ (Complex const &c) {
        //     Complex res;
        //     res.real = this->real + c.real;
        //     res.imag = this->imag + c.imag;
        //     return res;
        // };
        Complex operator+ (Complex const &c);

        void display() {
            cout<<real<<" + i"<<imag<<endl;
        }
};
Complex Complex::operator+ (Complex const &c) {
    Complex res;
    res.real = this->real + c.real;
    res.imag = this->imag + c.imag;
    return res;
}


// Runtime Polymorphism
class Base {
    public:
        virtual void print() {
            cout<<"Base print function"<<endl;
        }
        void display() {
            cout<<"Base display function"<<endl;
        }
};

class Derived : public Base {
    public:
        void print() {
            cout<<"Derived print function"<<endl;
        }
        void display() {
            cout<<"Derived display function"<<endl;
        }
};

int main() {
    Test t;
    t.foo();
    t.foo(3);
    t.foo(6.9);

    Complex c1(12, 7);
    Complex c2(6, 7);
    Complex c3 = c1 + c2;
    c3.display();

    Base *baseptr;
    Derived d;
    baseptr = &d;
    baseptr->print();
    baseptr->display();

    return 0;
}