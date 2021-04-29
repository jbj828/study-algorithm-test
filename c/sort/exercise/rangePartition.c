#include <stdio.h>

void swap(int arr[], int idx1, int idx2) {
  int temp;

  temp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;
}

void rangePartition(int arr[], int size, int lower, int higher) {
  int left = 0;
  int right = size - 1;
  int i = 0;

  while (i <= right) {
    if (arr[i] < lower) {
      swap(arr, i, left);
      i++;
      left++;
    } else if (arr[i] > higher) {
      swap(arr, i, right);
      right--;
    } else {
      i++;
    }
  }
}

int main() {
  int arr[] = {1, 21, 3, 4, 15, 23, 5, 8, 10, 9, 6, 17, 13};
  rangePartition(arr, sizeof(arr) / sizeof(int), 10, 15);

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}