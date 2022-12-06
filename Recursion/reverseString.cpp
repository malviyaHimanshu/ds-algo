// Reverse a string using recursion

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void reverse(string s) {
    // binod
    if(s.length()==0) {
        return;
    }
    reverse(s.substr(1)); // substring s except the first element
    cout<<s[0];
}

int main() {
    string s = "binod";
    reverse(s);

    return 0;
}