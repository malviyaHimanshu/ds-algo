// Pair Sum Problem
// Check if there exist two elements in an array such that their sum is equal to given k.

#include<iostream>
#include<climits>
#pragma GCC optimise("Ofast")
using namespace std;

// O(n^2)
bool bruteForce(int a[], int n, int k) { 
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(k == a[i] + a[j]) {
                cout<<"("<<i<<", "<<j<<")"<<endl;
                return true;
            }
        }
    }
    return false;
}

// O(n)
bool optimised(int a[], int n, int k) {
    int start=0, end=n-1;
    int sum;
    for(int i=0; i<n; i++) {
        sum = a[start] + a[end];
        if(sum < k) {
            start++;
        } else if(sum > k) {
            end--;
        } else if(sum==k) {
            cout<<"("<<start<<", "<<end<<")"<<endl;
            return true;
        }
    }
    return false;
}

int main() {
    int n, k; cin>>n>>k;
    int a[n]; for(int i=0; i<n; i++) { cin>>a[i]; }

    bruteForce(a, n, k);
    optimised(a, n, k);

    return 0;
}