// Bit Manipulation

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

bool getBit(int n, int i) {
    return n & (1<<i);
}

int setBit(int n, int i) {
    return n | (1<<i);
}

int clearBit(int n, int i) {
    return n & ~(1<<i);
}

int updateBit(int n, int i, int bit) {
    int clearedBit = clearBit(n, i);
    return clearedBit | (bit<<i);
}

int main() {
    // Get the bit at position i
    cout<<getBit(5, 2)<<endl;

    // setting the bit at position i to 1
    cout<<setBit(5, 1)<<endl;

    // clearing the bit at position i by 0
    cout<<clearBit(5, 0)<<endl;

    // updating the bit at position i by given value
    cout<<updateBit(5, 1, 1)<<endl;

    return 0;
}