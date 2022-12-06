
#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// Generate all substring of a string
// abc
/*
    start with an empty string
                                ""
                A                               ""
        AB              A               B               ""
    ABC     AB      AC      A       BC      B       C       ""

    focus on this tree, at each level we do two things 
    --> add a character or keep it as it is
*/
void substring(string s, string ans) {

    if(s.length()==0) {
        cout<<"{"<<ans<<"}"<<endl;
        return;
    }

    char ch = s[0];
    string rest = s.substr(1);
    substring(rest, ans+ch);
    substring(rest, ans);
}

// Generate all substring of a string using ASCII
// Here we have three things to do
//      dont add a character or add a character or add the ASCII value of that character
void substringASCII(string s, string ans) {
    if(s.length()==0) {
        cout<<"{"<<ans<<"}"<<endl;
        return;
    }
    char ch = s[0];
    string rest = s.substr(1);
    substringASCII(rest, ans);
    substringASCII(rest, ans+ch);
    substringASCII(rest, ans+to_string((int)ch));
}

int main() {
    substring("ABC", "");
    cout<<endl;
    substringASCII("AB", "");

    return 0;
}