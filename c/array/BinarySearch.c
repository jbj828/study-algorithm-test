#include <stdio.h>

int BinarySearch(int arr[], int size, int value) {
  int low = 0, mid;
  int high = size - 1;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == value) {
      return mid;
    } else if (arr[mid] < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(int);
  int value = 4;

  int ret = BinarySearch(arr, size, value);
  printf("%d", ret);
  return 0;
}