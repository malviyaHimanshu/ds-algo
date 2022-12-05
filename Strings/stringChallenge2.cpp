// Form the biggest number from the numerical string

#include<iostream>
#include<string>
#include<algorithm>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    string str;
    getline(cin, str);

    // sort in descending order
    sort(str.begin(), str.end(), greater<int>());
    cout<<str<<endl;

    return 0;
}