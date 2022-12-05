// Output the maximum occured character in the string

#include<iostream>
#include<string>
#include<climits>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int alphabets[26];
    for(int i=0; i<26; i++) alphabets[i] = 0;

    for(int i=0; i<str.length(); i++) {
        alphabets[str[i]-'a']++;
    }

    int maxEle=INT_MIN;
    char ans='a';
    for(int i=0; i<26; i++) {
        if(maxEle < alphabets[i]) {
            maxEle = alphabets[i];
            ans = i+'a';
        }
    }
    cout<<maxEle<<endl;
    cout<<ans<<endl;

    return 0;
}