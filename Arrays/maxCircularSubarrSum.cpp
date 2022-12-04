// Maximum Circular Subarray Sum
// O(n)

#include<iostream>
#include<climits>
#pragma GCC optimise("Ofast")
using namespace std;

int Kadane(int a[], int n) {
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0; i<n; i++) {
        currSum += a[i];
        if(currSum<0)
            currSum=0;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    int n; cin>>n;
    int a[n]; for(int i=0; i<n; i++) { cin>>a[i]; }

    int nonwrapSum=Kadane(a, n);
    int totalSum=0, ncElementSum=INT_MIN;
    // for finding the noncontributing elements 
    // invert the sign of every element in the array and use the kadane's algo
    for(int i=0; i<n; i++) {
        totalSum += a[i];
        a[i] = -a[i];
    }
    // non-contributing element
    ncElementSum = -Kadane(a, n);
    // max subarray sum = total sum - sum of noncontributing elements
    int wrapSum = totalSum-ncElementSum;
    cout<<max(wrapSum, nonwrapSum)<<endl;

    return 0;
}