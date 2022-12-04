// Given array = 10 16 7 14 5 3 12 9
// Reduced output array = 4 7 2 6 1 0 5 3

#include<iostream>
#include<vector>
using namespace std;

bool compareByFirst(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

pair<int, int> make_pair(int first, int second) {
    pair<int, int> p;
    p.first = first;
    p.second = second;
    return p;
}

int main() {
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    for(int element : arr) {
        cout<<element<<" "; 
    }
    cout<<endl;

    vector< pair<int, int> > vect;
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) {
        vect.push_back(make_pair(arr[i], i));
    }
    sort(vect.begin(), vect.end(), compareByFirst);

    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) {
        arr[vect[i].second] = i;
    }
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}