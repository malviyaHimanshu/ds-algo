// count the number of paths possible in maze

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int ways(int starti, int startj, int endi, int endj) {
    if(starti == endi && startj == endj) {
        return 1;
    }
    if(starti > endi || startj > endj) {
        return 0;
    }

    return ways(starti+1, startj, endi, endj) + ways(starti, startj+1, endi, endj);
}

int main() {
    cout<<ways(0, 0, 2, 2)<<endl;

    return 0;
}