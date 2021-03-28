#include <stdio.h>

int maxCircularSum(int arr[], int n) {
  int sumAll = 0;
  int currVal = 0;
  int maxVal;

  for (int i = 0; i < n; i++) {
    sumAll += arr[i];
    currVal += ((i + 1) * arr[i]);
  }

  maxVal = currVal;
  for (int i = 1; i < n; i++) {
    currVal = (currVal + sumAll) - (n * arr[n - i]);
    if (currVal > maxVal) {
      maxVal = currVal;
    }
  }
  return maxVal;
}

int main() {
  int arr[] = {10, 9, 8, 7, 6};
  printf("%d", maxCircularSum(arr, sizeof(arr) / sizeof(int)));
}