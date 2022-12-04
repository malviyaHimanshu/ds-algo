// given an arr find the smallest missing positive number in the array.

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    // find the maximum positive number
    int max=a[0];
    for(int i=0; i<n; i++) {
        if(max < a[i]) {
            max = a[i];
        }
    }

    bool checkArr[max];
    for(int i=0; i<max; i++) {
        checkArr[i] = false;
    }
    for(int i=0; i<n; i++) {
        if(a[i] >= 0) {
            checkArr[a[i]] = true;
        }
    }

    for(int i=0; i<max; i++) {
        if(checkArr[i] == false) {
            cout<<"Smallest Positive Missing Number : "<<i<<endl;
            break;
        }
    }

    return 0;
}