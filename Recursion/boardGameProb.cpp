// Count the number of paths possible from start point to end point in gameboard

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int ways(int start, int end) {
    // base case 
    if(start==end) {
        return 1;
    }
    if(start > end) {
        return 0;
    }

    // recursive case
    int count=0;
    for(int i=1; i<=6; i++) {
        count += ways(start+i, end);
    }
    return count;
}

int main() {
    cout<<ways(0, 3)<<endl;

    return 0;
}