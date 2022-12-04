// Maximum Subarray Sum using Cumulative Sum Approach
// O(n^2)

#include<iostream>
#include<climits>
#pragma GCC optimise("Ofast")
using namespace std;

int main() {
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    // forming the cumulative sum array wrt first element
    int cSumArr[n], sum=0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        cSumArr[i] = sum;
    }

    // check the sum of subarrays with the help of Cumulative sum array
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<i; j++) {
            sum = cSumArr[i] - cSumArr[j];
            maxSum = max(sum, maxSum);
        }
    }
    
    cout<<maxSum<<endl;

    return 0;
}