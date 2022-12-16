// Quick Sort - Divide and Conquer 

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    Algorithm
    - Choose one pivot element from the array
    - Partition the array from the pivot such that
        - all the elements in left side should be less than the pivot
        - all the elements in right side should be greater than the pivot
    - Perform the quick sort recursively from left to pivot and pivot+1 to right.

    Best case time complexity : O(NlogN)
        - when pivot element is in middle
    Worst case time complexity : O(N^2)
        - when pivot is at end
*/

int Partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i=left-1;
    for(int j=left; j<right; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[right], arr[i+1]);
    return i+1;
}

void QuickSort(int arr[], int left, int right) {
    if(left < right) {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot);
        QuickSort(arr, pivot+1, right);
    }
}

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    QuickSort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0; 
}