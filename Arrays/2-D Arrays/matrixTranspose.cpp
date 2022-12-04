// Matrix Transpose
// Given square matrix

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int n; cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>a[i][j];
        }
    }

    // swap (i,j) and (j,i) in upper matrix
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}