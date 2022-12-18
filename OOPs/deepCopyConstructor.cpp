// Deep Copy Constructor

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class Test {
    int a;
    int *p;

    public:
        Test(int x) {
            a = x;
            p = new int[a];
        }
        Test(Test &t) {
            a = t.a;
            // p = t.p;     // shallow copy
            p = new int[a]; // deep copy
        }
};

int main() {

    return 0;
}