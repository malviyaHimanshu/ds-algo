// Write a program to find a unique number in an array where all the numbers expect one, are present twice

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int n; cin>>n;
    int a[n]; for(int i=0; i<n; i++) cin>>a[i];

    // APPROACH 1
    for(int i=0; i<n; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            if((a[i] ^ a[j]) != 0 && j!=i) {
                count++;
            }
        }
        if(count == n-1) {
            cout<<"Unique Number : "<<a[i]<<endl;
        }
    }

    // APPROACH 2 (optimised)
    // XOR of two equal number given ZERO 
    // hence, all the twice occured element will get zero and the unique one will remains
    int xorsum=0;
    for(int i=0; i<n; i++) {
        xorsum ^= a[i];
    }
    cout<<xorsum<<endl;

    return 0;
}