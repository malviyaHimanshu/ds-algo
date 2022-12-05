// Check if given number is power of two

#include<iostream>
#include<math.h>
#pragma GCC optimise("Ofast")
using namespace std;

int getBit(int n, int i) {
    return (n & (1<<i)) != 0; 
}

int main() {
    int n; cin>>n;

    // APPROACH 1
    int count=0;
    for(int i=0; i<=log2(n); i++) {
        if(getBit(n, i)==1) {
            count++;
        }
    }
    if(count==1) {
        cout<<"Power of 2"<<endl;
    } else {
        cout<<"Not a power of 2"<<endl;
    }

    // APPROACH 2 (Optimised)
    /*
        (n) 8 : 1000
        (n-1) 7 : 0111
        n & n-1 : 0000
    */
    if(n && (n & n-1)) {
        cout<<"Not a power of 2"<<endl;
    } else {
        cout<<"Power of 2"<<endl;
    }

    return 0;
}