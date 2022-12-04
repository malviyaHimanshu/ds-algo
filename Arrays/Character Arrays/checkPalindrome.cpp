// Check Palindrome

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int n; cin>>n;
    char s[n+1];
    cin>>s;

    bool isPalindrome=true;
    for(int i=0; i<n; i++) {
        if(s[i] != s[n-i-1]) {
            isPalindrome=false;
            break;
        }
    }
    cout<<isPalindrome<<endl;

    return 0;
}