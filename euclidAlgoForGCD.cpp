// Euclid Algorithm for finding GCD

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    24 = 2 x 2 x 2 x 3
    42 = 2 x 3 x 7
    GCD(24, 42) = 2 x 3 = 6

    NOTE: substraction does NOT affect GCD
        42 - 24 = 18 (GCD(42, 24) = GCD(24, 18))
        24 - 18 = 6
        18 - 6 = 6
        6 - 6 = 0 (STOP)
    then GCD is 6.

    Instead of Subtracting find the remainder (%).
    42 % 24 = 18
    24 % 18 = 6
    18 % 6 = 0
*/

int GCD(int n1, int n2) {
    while(n2 != 0) {
        int rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    }
    return n1;
}

int main() {
    int n1, n2; cin>>n1>>n2;
    cout<<GCD(n1, n2)<<endl;

    return 0;
}