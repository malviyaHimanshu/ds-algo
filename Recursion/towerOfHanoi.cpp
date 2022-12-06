// Tower of Hanoi using Recursion
/*
    There are three rodes
    A (souce)   B (helper)   C (destination)
    1
    2
    3
    4

    Need to put all the three element to c rode but 
    no element should be below a larger element.

    Recursive Approach -> 
        Take the (n-1) elements and put them on B
        now take the nth element and put that on C
        finally put (n-1) elements to rode C.
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;


void toh(int n, char src, char des, char hel) {
    // base case
    if(n==0) {
        return;
    }
    // recursive case
    toh(n-1, src, hel, des);
    cout<<"Move from "<<src<<" to "<<des<<endl;
    toh(n-1, hel, des, src);
}


int main() {
    toh(2, 'A', 'C', 'B');

    return 0;
}