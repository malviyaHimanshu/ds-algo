// Find the first and last occurence of an element in an array

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int firstOcc(int a[], int n, int i, int value) {
    if(i==n) {
        return -1;
    }
    if(a[i] == value) {
        return i;
    }
    return firstOcc(a, n, i+1, value);
}

int lastOcc(int a[], int n, int i, int value) {
    if(i==n) {
        return -1;
    }
    int restArr = lastOcc(a, n, i+1, value);
    if(restArr != -1) {
        return restArr;
    }
    if(a[i] == value) {
        return i;
    }
    return -1;
}


int main() {
    int arr[7] = {4, 2, 1, 2, 5, 2, 7};
    cout<<firstOcc(arr, 7, 0, 2)<<endl;
    cout<<lastOcc(arr, 7, 0, 2)<<endl;

    return 0;
}