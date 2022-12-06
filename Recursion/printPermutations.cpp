// Print all possible permutations of a string

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// ABC
/*      Brainstorming
    ""  -> ABC, ACB
        -> BAC, BCA
        -> CAB, CBA
                        ABC
        (fix A)         (fix B)         (fix C)
        BC,A            AC,B            AB,C
    C,AB    B,AC    C,BA    A,BC    B,CA    A,CB
*/

void permutation(string s, string ans) {
    if(s.length()==0) {
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        string rest = s.substr(0, i) + s.substr(i+1);
        permutation(rest, ans + ch);
    }
}

int main() {
    permutation("ABC", "");

    return 0;
}