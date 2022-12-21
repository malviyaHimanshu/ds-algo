// Stack (LIFO)
// Stores a list of items in which an item can be added to or removed from the list at one node

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

#define size 100

// Array implementation
class Stack {
    int *arr;
    int top;
    public:
        Stack() {
            arr = new int[size];
            top = -1;
        }

        void push(int x) {
            if(top==size-1) {
                cout<<"stack overflow"<<endl;
                return;
            }
            top++;
            arr[top] = x;
        }

        void pop() {
            if(top==-1) {
                cout<<"stack empty"<<endl;
                return;
            }
            top--;
        }

        int Top() {
            if(top==-1) {
                cout<<"stack empty"<<endl;
                return -1;
            }
            return this->arr[top];
        }

        bool empty() {
            return top==-1;
        }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;

    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;

    return 0;
}