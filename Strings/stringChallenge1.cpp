// Strings in CPP

#include<iostream>
#include<string>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for(int i=0; i<str.length(); i++) {
        if(str[i] >= 97) {
            str[i] -= 32;
        } else {
            str[i] += 32;
        }
    }
    cout<<str<<endl;

    // in build function
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str<<endl;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str<<endl;

    return 0;
}