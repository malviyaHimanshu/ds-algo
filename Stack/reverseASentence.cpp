// reverse a sentence using stack

#include<iostream>
#include<stack>
#include<string>
#pragma GCC optimise("Ofast")
using namespace std;

void reverseSentence(string s) {
    stack<string> st;
    string word = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ' || i==s.length()-1) {
            st.push(word);
            word = "";
        } else {
            word += s[i];
        }
    }
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;
}


int main() {
    string s = "Hey, how are you doing?";
    reverseSentence(s);

    return 0;
}