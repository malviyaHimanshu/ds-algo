/*
Types of Inheritance

    - Single Inheritance
        class B : public A {

        };

    - Multiple Inheritance
        class C : public A, public B {

        };

    - Multilevel Inheritance
        class B : public A {

        };
        class C : public B {

        };
        - C can access class B as well as class A protected/public attributes.

    - Hybrid Inheritance (Mixture of two or more)
    - Hierarchical Inheritance
*/

/*
    What's the meaning of following inheritance?
        class B : private A {

        };
    -> It means that all the protected and public attributes of class A 
    will go to class B's private access section
*/


#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class A {
    public:
        void foo() {
            cout<<"Inherited A"<<endl;
        }
};
class B {
    public:
        void boo() {
            cout<<"Inherited B"<<endl;
        }
};

class C : public A, public B {

};

int main() {
    C c;
    c.foo();
    c.boo();

    return 0;
}
