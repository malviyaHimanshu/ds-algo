// subarray vs subsubsequence
// find sum of all subarrays
// time complexity = O(n2)

#include<iostream>
using namespace std;

void printArr(int arr[], int start, int end) {
  int sum=0;
  for(int i=start; i<=end; i++) {
    sum += arr[i];
    cout<<arr[i]<<" + ";
  }
  cout<<" = "<<sum<<endl;
}

int main() {
  int arr[] = {2, 4, 6, 1, 8, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"n = "<<n<<endl;

  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      printArr(arr, i, j);
    }
    cout<<endl;
  }

  return 0;
}