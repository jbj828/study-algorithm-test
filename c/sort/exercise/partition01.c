#include <stdio.h>

void partition01(int arr[], int size) {
  int zeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) zeroCount++;
  }

  for (int i = 0; i < zeroCount; i++) {
    arr[i] = 0;
  }

  for (int i = zeroCount; i < size; i++) {
    arr[i] = 1;
  }
}

int main() {
  int arr[] = {0, 1, 1, 0, 0, 0, 1, 1, 0};
  partition01(arr, sizeof(arr) / sizeof(int));

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}