// Reverse the stack

#include<iostream>
#include<stack>
#pragma GCC optimise("Ofast")
using namespace std;

void insertAtBottom(stack<int> &st, int element) {
    if(st.empty()) {
        st.push(element);
        return;
    }
    
    int topEle = st.top();
    st.pop();
    insertAtBottom(st, element);

    st.push(topEle);
}

void reverse(stack<int> &st) {
    if(st.empty()) {
        return;
    }
 
    int element = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, element);
}

void display(stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    } cout<<endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    display(s);
    
    reverse(s);
    display(s);

    return 0;
}