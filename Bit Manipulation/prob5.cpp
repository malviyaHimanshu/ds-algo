// Program to find 2 unique numbers where all number except two, are present twice
// n = 8
// arr = [2 4 6 7 4 5 6 2]
// unique numbers : 7 5

#include<iostream>
#pragma GCC optimise("Ofast")
    using namespace std;

int getBit(int n, int i) {
    return (n & (1<<i)) != 0;
}

int main() {
    int n; cin>>n;
    int a[n]; for(int i=0; i<n; i++) cin>>a[i];

    int xorsum=0;
    for(int i=0; i<n; i++) {
        xorsum ^= a[i];
    }
    int oldxor = xorsum;

    int setbit=0, pos=0;
    while(setbit!=1) {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int newxor=0;
    for(int i=0; i<n; i++) {
        if(getBit(a[i], pos-1)) {
            newxor ^= a[i];
        }
    }

    cout<<newxor<<" "<<(oldxor^newxor)<<endl;

    return 0;
}