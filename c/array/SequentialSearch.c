#include <stdio.h>

int SequentialSearch(int arr[], int size, int value) {
  int i;
  int result = -1;

  for (i = 0; i < size; i++) {
    if (arr[i] == value) {
      result = i;
    }
  }
  return result;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(int);
  int value = 4;

  int ret = SequentialSearch(arr, size, value);
  printf("%d", ret);
  return 0;
}