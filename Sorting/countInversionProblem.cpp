// Count Inversion - Merge Sort
/*
    Count the inversions in the given array.
    Two elements a[i] and a[j] form an inversion 
        if a[i] > a[j] and i < j

    eg. [ 3 5 6 9 1 2 7 8 ]
        possible inversions = 10
        (3,1) (3,2) (5,1) (5,2) (6,1) 
        (6,2) (9,1) (9,2) (9,7) (9,8)
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

// Brute force approach
int countInversions(int arr[], int n) {
    int inversions=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

// using the merge sort
int invCount=0;

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
        if(leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
            // THIS IS IMPORTANT HERE
            /*
                left arr            right arr
                3 5 8 9             1 2 4 7
                if 3 > 1 then 1 inversion but at the same time we can say
                there are 3 more inversions as both left and right arr are sorted.
                so if at a[i] > a[j] then the number of inversions possible is
                    + ( size of left arr - i )
            */
            invCount += (n1-i);
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

int countInversionUsingMerge(int arr[], int n) {
    MergeSort(arr, 0, n-1);
    return invCount;
}

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // int arr[] = {3,5,6,9,1,2,7,8};
    cout<<countInversions(arr, n)<<endl;
    cout<<countInversionUsingMerge(arr, n)<<endl;

    return 0;
}