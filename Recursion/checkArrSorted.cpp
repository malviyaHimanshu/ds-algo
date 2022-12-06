// Check if given array is sorted or not

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

bool isSorted(int arr[], int start, int end, int n) {
    if(start == end)
        return true;
    return arr[start] < arr[start+1] && isSorted(arr, start+1, end, n-1);
}

bool isSortedUsingPointer(int arr[], int n) {
    if(n==1)
        return true;
    return arr[0] < arr[1] && isSortedUsingPointer(arr+1, n-1);
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    cout<<isSorted(a, 0, 4, 5)<<endl;
    cout<<isSortedUsingPointer(a, 5)<<endl;

    return 0;
}