// Move all X to end of the string

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// axxbdxcefxhix -> abdcefhixxxxx

string moveX(string s) {
    // base case
    if(s.length()==0) {
        return "";
    }
    // recursive case
    if(s[0] == 'x') {
        return moveX(s.substr(1)) + s[0];
    }
    return s[0] + moveX(s.substr(1));
}

int main() {
    string s = "axxbdxcefxhix";
    cout<<moveX(s)<<endl;

    return 0;
}