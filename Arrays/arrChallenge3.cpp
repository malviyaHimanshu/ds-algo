// Longest arithemetic subarray (Google Kickstart)

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

    int ans = 2;
    int difference = arr[1] - arr[0];
    int current = 2;
    int j = 2;

    while(j<n) {
      if(difference == arr[j] - arr[j-1]) {
        current++;
      } else {
        difference = arr[j] - arr[j-1];
        current = 2;
      }
      ans = max(ans, current);
      j++;
    }

    cout<<ans<<endl;

  }

  return 0;
}