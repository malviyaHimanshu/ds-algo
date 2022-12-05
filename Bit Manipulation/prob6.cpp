// Program to find One unique number in array where all element except one, are present thrice.
// n = 10
// [1 3 2 3 4 2 1 1 3 2]
// unique number = 4

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int getBit(int n, int i) {
    return (n & (1<<i)) != 0;
}

int setBit(int n, int i) {
    return (n | (1<<i));
}

int main() {
    int n; cin>>n;
    int a[n]; for(int i=0; i<n; i++) cin>>a[i];

    int nbits[32]; for(int i=0; i<32; i++) nbits[i]=0;
    int number=0;
    for(int pos=0; pos<32; pos++) {
        for(int i=0; i<n; i++) {
            if(getBit(a[i], pos)) {
                nbits[pos]++;
            }
        }
        if(nbits[pos] % 3 != 0) {
            number = setBit(number, pos);
        }
    }
    cout<<number<<endl;

    return 0;
}