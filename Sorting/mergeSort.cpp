// Merge Sort - Divide and Conquer

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    Algorithm
    - First find the mid point
    - Divide the array into two parts from that point
    - Perform merge sort recursively on the both the arrays
    - Merge both the arrays such the they are in sorted order

    Time Complexity Analysis
        T(n) = 2T(n/2) + n              x 1
        T(n/2) = 2T(n/4) + n/2          x 2
        T(n/4) = 2T(n/8) + n/4          x 4 
        .                               .
        .                               .
        T(1) = 1                        x (2 ^ logn) = n

        Levels: 
            n/2^k = 1
            n = 2^k 
            k = logn

        Adding all the equations after multiplying to x1, x2, x4 ...
        T(n) + 2T(n/2) + 4T(n/4) +...+ nT(1) = 2T(n/2) + n + 4T(n/4) + n +...+ nT(1) + n
        T(n) = n + n + n + n + .... n (logn times)
             = nlogn

    [ T(N) = NlogN ]
*/

void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;
    int leftarr[n1], rightarr[n2];
    for(int i=0; i<n1; i++) {
        leftarr[i] = arr[left+i];
    }
    for(int i=0; i<n2; i++) {
        rightarr[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=left;
    while(i < n1 && j < n2) {
        if(leftarr[i] < rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = leftarr[i];
        i++; k++;
    }
    while(j < n2) {
        arr[k] = rightarr[j];
        j++; k++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        
        Merge(arr, left, mid, right);
    }
}

int main() {
    int n; cin>>n;
    int arr[n];    
    for(int i=0; i<n; i++) cin>>arr[i];

    MergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}