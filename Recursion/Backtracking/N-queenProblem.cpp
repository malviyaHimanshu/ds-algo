// N Queen Problem
// Put N queens in matrix such that no queen should able to attack on other queen

#include<iostream>
#include<vector>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    n = 4 (0 -> queen absent)
    0 0 0 0
    0 0 0 0
    0 0 0 0
    0 0 0 0
*/

bool isSafe(int **arr, int x, int y, int n) {
    for(int i=0; i<x; i++) {
        if(arr[i][y]==1) {
            return false;
        }
    }

    int row=x, col=y;
    while(row>=0 && col>=0) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    row=x, col=y;
    while(row>=0 && col<n) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool NQueen(int **matrix, int row, int n) {
    if(row>=n) {
        return true;
    }

    for(int i=0; i<n; i++) {
        if(isSafe(matrix, row, i, n)) {
            matrix[row][i] = 1;
            if(NQueen(matrix, row+1, n)) {
                return true;
            }
            matrix[row][i] = 0; // backtracking
        }
    }
    return false;
}


int main() {
    int n; cin>>n;
    
    int **matrix = new int*[n];
    for(int i=0; i<n; i++) {
        matrix[i] = new int[n];
        for(int j=0; j<n; j++)
            matrix[i][j]=0;
    }

    if(NQueen(matrix, 0, n)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<matrix[i][j]<<" ";
            } cout<<endl;
        }
    }

    return 0;
}