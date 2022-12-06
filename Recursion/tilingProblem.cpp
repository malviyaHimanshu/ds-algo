// Tiling Problems
// Given '2 x n' board and tiles of size '2 x 1', count the number to tile the given board

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// if tile placed horizontally -> ways(n-2);
// if tile placed vertically -> ways(n-1);

int ways(int n) {
    if(n==1 || n==0) {
        return n;
    }
    return ways(n-1) + ways(n-2);
}

int main() {
    cout<<ways(4)<<endl;

    return 0;
}