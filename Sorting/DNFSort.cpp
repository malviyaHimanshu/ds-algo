// DNF (Dutch National Flag) Sort or 0,1,2 Sort

/*
    Array will be divided to 4 parts
        - start to low ( zeros ) RED
        - low to mid ( ones ) WHITE
        - mid to high ( unknown )
        - high to end ( twos ) BLUE
    
    -> aim is to reduce the unknown array

    start checking with mid pointer
    if arr[mid]=0 then 
        swap arr[low] <-> arr[mid]
        low++, mid++
    if 1 then mid++
    if 2 then 
        swap arr[mid] <-> arr[high]
        high--

    TIME COMPLEXITY ANALYSIS
        O(N)
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void DNFSort(int arr[], int n) {
    int low=0, mid=0, high=n-1;
    while(mid<=high) {
        if(arr[mid]==0) {
            swap(arr[low], arr[mid]);
            low++, mid++;
        } else if(arr[mid]==1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    DNFSort(arr, 9);
    for(int i=0; i<9; i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}