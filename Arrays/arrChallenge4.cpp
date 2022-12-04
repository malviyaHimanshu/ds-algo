// Record Breaker

#include<iostream>
using namespace std;

int main() {
  int T;
  cin>>T;

  while(T--) {

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
      cin>>arr[i];
    }

    int max = arr[0], rbdays=0;
    for(int i=0; i<n-1; i++) {
      if(max < arr[i]) {
        max = arr[i];
        if(arr[i] > arr[i+1]) {
          rbdays++;
        }
      }
    }

    cout<<rbdays<<endl;

  }

  return 0;
}