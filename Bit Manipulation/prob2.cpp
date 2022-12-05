// Write a program to count the number of ones in binary rep of a number

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
    int noOfOne=0;
    for(int i=0; i<=log2(n); i++) {
        if(getBit(n, i)) {
            noOfOne++;
        }
    }
    cout<<noOfOne<<endl;

    // APPROACH 2 (Optimised)
    /*
        (n) 19 = 01011
        (n-1) 18 = 01010
        (n) n & n-1 = 01010
    */

    int count=0;
    while(1) {
        if(n==0)
            break;
        n = n & n-1;
        count++;
    }
    cout<<count<<endl;

    return 0;
}