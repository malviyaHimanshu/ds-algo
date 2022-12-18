// Pointer to Class

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class Rectangle {
    public:
        int length;
        int breadth;

        int area() {
            return length*breadth;
        }
        int perimeter() {
            return 2*(length+breadth);
        }
};

int main() {
    // object created to stack
    Rectangle r1;
    // pointer to object rectangle
    // Rectangle *ptr;
    // ptr = &r1;

    // dynamic object created to heap
    Rectangle *ptr = new Rectangle; 
    ptr->length = 10;
    ptr->breadth = 5;
    cout<<ptr->area()<<endl;
    cout<<ptr->perimeter()<<endl;

    return 0;
}