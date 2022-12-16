// Permutation is a rearrangement of members of a sequence into a new sequence.

/*
    Given an array nums of integers, return all the possible permutations.
    You can return the answer in any order.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#pragma GCC optimise("Ofast")
using namespace std;

vector<vector<int> > ans;
void permutation(vector<int> arr, int index) {
    if(index == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size(); i++) {
        if(i!=index and arr[i]==arr[index])
            continue;
        swap(arr[i], arr[index]);
        permutation(arr, index+1);
        swap(arr[i], arr[index]);
    }
}

int main() {
    int n; cin>>n;
    vector<int> arr;
    for(auto i: arr) cin>>i;

    permutation(arr, 0);

    for(auto v: ans) {
        for(auto i: v) {
            cout<<i<<" ";
        }cout<<endl;
    } 

    return 0;
}