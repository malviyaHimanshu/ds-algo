// Write a program to generate all possible subsets of a set
// {a, b, c}

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    abc
    000     0
    001     1
    010     2
    011     3
    100     4
    101     5
    110     6
    111     7
*/

void subset(int a[], int n) {
    for(int i=0; i<(1<<n); i++) {
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                cout<<a[j]<<" ";
            }
        }cout<<endl;
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    subset(arr, 4);

    return 0;
}