// Insertion sort in C++

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

// function for Insertion Sort
int *insertionSort(int arr[], int n) {
  int end=1;
  for(int i=1; i<n; i++) {
    int current = arr[i];
    int j = i-1;
    while(current < arr[j] && j >= 0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = current;
  }

  return arr;
}

int main() {
  int unsortedArr[6] = {5, 7, 2, 8, 0, 1};
  int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

  cout << "Unsorted Array : ";
  printArr(unsortedArr, size);

  int *sortedArr = insertionSort(unsortedArr, size);
  cout << "Sorted Array : ";
  printArr(sortedArr, size);

  return 0;
}