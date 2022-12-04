// Matrix Search when rows and columns are in sorted order
// Approach 2

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int m, n, k; cin>>m>>n>>k;
    int a[m][n];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>a[i][j];
        }
    }

    int row=0, col=n-1;
    while(row < n && col >= 0) {
        if(k == a[row][col]) {
            cout<<"TRUE"<<endl;
            cout<<"("<<row<<", "<<col<<")"<<endl;
            return 0;
        } else if(k < a[row][col]) {
            col--;
        } else if(k > a[row][col]) {
            row++;
        }
    }
    cout<<"FALSE"<<endl;

    return 0;
}