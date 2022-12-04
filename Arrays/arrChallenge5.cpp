// given unsorted array A size N
// find continous subarray which adds to a given number S

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int currsum(int a[], int start, int end) {
    int sum=0;
    for(int i=start; i<=end; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int n=4, s=5;
    int a[] = {1, 2, 3, 8};

    int start=0, end=0;
    for(int i=0; i<2*n; i++) {
        if(currsum(a, start, end) < s) {
            end++;
        } else if(currsum(a, start, end) > s) {
            start++;
        } else if(currsum(a, start, end) == s) {
            cout<<"Array found from "<<start+1<<" to "<<end+1<<endl;
            break;
        } 
    }

    return 0;
}