// Largest word in a sentence

#include<iostream>
#include<string.h>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    char s[100];
    cin.getline(s, 100);

    int i=0, count=0, maxLen=0;
    while(s[i] != '\0') {
        count++;
        if(s[i] == ' ')
            count = 0;
        maxLen = max(maxLen, count);
        i++;
    }
    cout<<maxLen<<endl;

    return 0;
}