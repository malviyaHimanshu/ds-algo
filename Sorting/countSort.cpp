// Count Sort 
// Time complexity is better than other sorting techniques like merge sort and quick sort.

/*
    1) Find the count of each element in the array
    2) Calculate the position of each element in sorted array

    eg. 1 3 2 3 4 1 6 4 3
    count array     [ 0 2 1 3 2 0 1 ]
    index             0 1 2 3 4 5 6

    cumulative sum  [ 0 2 3 6 8 8 9 ]
    array

    sorted array    [ 1 1 2 3 3 3 4 4 6 ]

    TIME COMPLEXITY ANALYSIS
        = O(max(N, max(Ai)))
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void countSort(int arr[], int n, int sol[]) {
    int countarr[10] = {0};
    for(int i=0; i<n; i++) countarr[arr[i]]++;

    int sum=0;
    for(int i=0; i<10; i++) {
        sum += countarr[i];
        countarr[i] = sum;
    }

    for(int i=0; i<n; i++) {
        int value = arr[i];
        sol[--countarr[value]] = value;
    }
}

int main() {
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int sol[9] = {0};
    countSort(arr, 9, sol);
    for(int i=0; i<9; i++) {
        cout<<sol[i]<<" ";
    }cout<<endl;

    return 0;
}