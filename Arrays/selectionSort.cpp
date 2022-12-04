// selection sorting in CPP

#include<iostream>
using namespace std;


// function to swap two elements
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// function to print array
void printArr(int arr[], int n) {
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int * selectionSort(int arr[], int n) {
  int imin;
  for(int i=0; i<n-1; i++) {
    imin = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[imin]) {
        imin = j;
      }
    }
    // swap min with left most element
    swap(arr[imin], arr[i]);
  }
  return arr;
}


int main() {
  int unsortedArr[6] = {5, 7, 2, 8, 0, 1};
  int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

  cout << "Unsorted Array : ";
  printArr(unsortedArr, size);

  int *sortedArr = selectionSort(unsortedArr, size);
  cout << "Sorted Array : ";
  printArr(sortedArr, size);

  return 0;
}