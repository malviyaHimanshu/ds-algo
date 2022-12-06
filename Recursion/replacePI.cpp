// Replace pi with the 3.14 in a string

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// pippxxppiixiipi -> 3.14ppxxp3.14ixii3.14

void repPI(string s) {
    // base case 
    if(s.length()==0) {
        cout<<endl;
        return;
    }
    // recursive case
    if(s[0]=='p' && s[1]=='i') {
        cout<<"3.14";
        repPI(s.substr(2));
    } else {
        cout<<s[0];
        repPI(s.substr(1));
    }
}

int main() {
    string s = "pippxxppiixiipi";
    repPI(s);

    return 0;
}