// Wave Sort (Sorting like a wave)

/*
    arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ...

    arr[0]          arr[2]          arr[4]
            arr[1]          arr[3]          arr[5]

    TIME COMPLEXITY : O(N/2) => O(N)
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void waveSort(int arr[], int n) {
    for(int i=1; i<n; i+=2) {
        if(arr[i-1] <= arr[i]) {
            swap(arr[i-1], arr[i]);
        } 
        if(arr[i] >= arr[i+1] && i<=n-2) {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() {
    int arr[] = {1,3,4,7,5,6,2};
    waveSort(arr, 7);
    for(int i=0; i<7; i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}