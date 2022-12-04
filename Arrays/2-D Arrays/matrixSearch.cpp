// Matrix Search where rows and column both are in sorted order

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

    int i=0, j=0;
    while(a[i][j] < k) {
        i++; j++;
    }
    if(a[i][j]==k) {
        cout<<"("<<i<<", "<<j<<")"<<endl;
        return 0;
    }
    for(int row=0; row<i; row++) {
        if(a[i][row] == k) {
            cout<<"("<<i<<", "<<row<<")"<<endl;
        }
        if(a[row][i] == k) {
            cout<<"("<<row<<", "<<i<<")"<<endl;
        }
    }

    return 0;
}