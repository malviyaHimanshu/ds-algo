/*
    Types of fuctions in class
    - Constructors
        Rectangle();
        Rectangle(int l, int b);
        Rectangle(Rectangle &r);
    - Mutators (set)
        void setlength(int l);
        void setbreadth(int b);
    - Accessors (get)
        int getlength(int l);
        int getbreadth(int b);
    - Facilitators
        int area();
        int perimeter();
    - Inspector or Enquiry
        bool isSquare();
    - Destructor
        ~Rectangle()
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class Rectangle {
    int length;
    int breadth;

    public:
        Rectangle();
        Rectangle(int l, int b);
        Rectangle(Rectangle &r);

        int getLength() {       // inline function
            return length;
        };
        int getBreadth() {      // inline function
            return breadth;
        };
        void setLength(int l);
        void setBreadth(int b);

        inline int area();   // way of declaring inline function and writing definition outside the class
        int perimeter();    // it will be outside the main (not a inline function)

        bool isSquare();
        ~Rectangle();
};

Rectangle::Rectangle() {
    length = 1;
    breadth = 1;
}
Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}
Rectangle::Rectangle(Rectangle &r) {
    length = r.length;
    breadth = r.breadth;
}
void Rectangle::setLength(int l) {
    length = l;
}
void Rectangle::setBreadth(int b) {
    breadth = b;
}
bool Rectangle::isSquare() {
    return length==breadth;
}
Rectangle::~Rectangle() {
    cout<<"Destructor Called"<<endl;
}

int Rectangle::area() {    // it will become inline function
    cout<<"inline"<<endl;
    return length*breadth;
}
// Here area() will be just replaced wherever it is called (inside the main).
// but the perimeter() will be outside of the main function.
int Rectangle::perimeter() {
    cout<<"non-inline"<<endl;
    return 2*(length+breadth);
}

int main() {

    Rectangle r1(10, 10);
    if(r1.isSquare()) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}