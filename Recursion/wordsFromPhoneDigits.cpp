// Generate all possible words from phone digit
/*
    1 : . /     2 : abc     3 : def
    4 : ghi     5 : jkl     6 : mno
    7 : pqrs    8 : tuv     9 : wxyz
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

string keypad[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void words(string s, string ans) {
    if(s.length()==0) {
        cout<<ans<<endl;
        return;
    }
    char number = s[0];
    string code = keypad[number-'0'];
    string rest = s.substr(1);
    for(int i=0; i<code.length(); i++) {
        words(rest, ans + code[i]);
    }
}

int main() {
    words("23", "");

    return 0;
}