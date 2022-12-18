// Struct VS Class

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// In C++ struct can have function inside but C can NOT.
/*
    In C++, Structure and Class looks the same. 
    So what's the difference?
        - In structure everything is public by default unlike class.
    apart from that everything is same between structure and class.
    we can use anything depending on the requirement.
*/
struct Demo {
    int x;
    int y;

    void display() {
        cout<<x<<" "<<y<<endl;
    }
};

int main() {
    Demo d;
    d.x = 10;
    d.y = 20;
    d.display();

    return 0;
}