// Remove Duplicates in a string using recursion

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// aaaaabbbbbeeecdddd -> abecd

string removeDuplicate(string s) {
    // base case
    if(s.length()==0) {
        return s;
    }
    // recursive case
    if(s[0]==s[1])
        return removeDuplicate(s.substr(1));
    return s[0] + removeDuplicate(s.substr(1));
}

int main() {
    cout<<removeDuplicate("aaaaabbbbbeeecdddd")<<endl;

    return 0;
}