// Passing pointers with functions 

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void increment(int *p) {
    (*p)++;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;

    cout<<a<<" "<<b<<endl;
    swap(&a, &b);
    cout<<a<<" "<<b<<endl;

    increment(&a);
    increment(&b);
    cout<<a<<" "<<b<<endl;

    return 0;
}