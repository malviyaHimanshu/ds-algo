// Print numbers till n 
// 1) Decreasing Order
// 2) Increasing Order

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void printDecreasing(int n) {
    if(n==0) {
        cout<<endl;
    } else {
        cout<<n<<" ";
        printDecreasing(n-1);
    }
}

void printIncreasing(int n) {
    if(n==0) {
        cout<<endl;
    } else {
        printIncreasing(n-1);
        cout<<n<<" ";
    }
}


int main() {
    printDecreasing(10);
    printIncreasing(10);

    return 0;
}