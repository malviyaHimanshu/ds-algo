// given unsorted array A size N
// find continous subarray which adds to a given number S
// Second Approach

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int n, s;
    cin>>n>>s;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int i=0, j=0, sum=0;
    while(j<n && sum + arr[j] <= s) {
        sum += arr[j];
        j++;
    }

    if(sum == s) {
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    
    while(j<n) {
        sum += arr[j];
        while(sum > s) {
            sum -= arr[i];
            i++;
        }

        if(sum == s) {
            cout<<i+1<<" "<<j+1<<endl;
        }
        j++;
    }

    return 0;
}