/*
    Backtracking
    -> It is an algorithmic technique to solve recursive problems by trying to build
    every possible solution incrementally and removing those solution that fail to
    satisfy the constraints of the problem at any point of time.
*/

// Rat in a maze

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    (Maze Arr)          (Solution)
    1 0 1 0 1           1 0 0 0 0
    1 1 1 1 1           1 1 1 1 0
    0 1 0 1 0    -->    0 0 0 1 0
    1 0 0 1 1           0 0 0 1 1
    1 1 1 0 1           0 0 0 0 1
*/

bool isSafe(int **maze, int x, int y, int n) {
    if(x<n && y<n && maze[x][y]==1) {
        return true;
    }
    return false;
}

bool ratInMaze(int **maze, int x, int y, int n, int **sol) {
    // base case
    if(x==n-1 && y==n-1) {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y, n)) {
        sol[x][y] = 1;
        // go in right direction if can
        if(ratInMaze(maze, x+1, y, n, sol)) {
            return true;
        }
        // if not in right go in south direction if can
        if(ratInMaze(maze, x, y+1, n, sol)) {
            return true;
        }
        // if can't go in both direction then backtrack
        sol[x][y] = 0;  // backtrack
        return false;
    }
    return false;
}

int main() {
    int n; cin>>n;
    int **maze = new int*[n];
    for(int i=0; i<n; i++) {
        maze[i] = new int[n];
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>maze[i][j];
    
    int **sol = new int*[n];
    for(int i=0; i<n; i++) {
        sol[i] = new int[n];
        for(int j=0; j<n; j++)
            sol[i][j] = 0;
    }

    cout<<endl;
    if(ratInMaze(maze, 0, 0, n, sol)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"Not possible"<<endl;

    return 0;
}