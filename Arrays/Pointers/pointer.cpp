// Playing with the pointers in C++

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    int **q = &p;

    cout<<"Variable a = "<<a<<endl;
    cout<<"Address of a = "<<&a<<endl;

    cout<<"Pointer p which stores address of a : "<<p<<endl;
    cout<<"Pointer p which points to a (dereferencing) : "<<*p<<endl;
    cout<<"Address of pointer p = "<<&p<<endl;

    cout<<"Pointer q which stores address of pointer p : "<<q<<endl;
    cout<<"Pointer q which points to pointer p (dereferencing) : "<<*q<<endl;
    cout<<"Pointer q which points to pointer p which points to a (dual-dereferencing) : "<<**q<<endl;
    cout<<"Address of pointer q = "<<&q<<endl;

    return 0;
}