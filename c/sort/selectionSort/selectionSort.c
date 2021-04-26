#include <stdio.h>

void swap(int* value1, int* value2) {
  int temp;

  temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

void selectionSort(int arr[], int size) {
  for (int i = size - 1; i > 0; i--) {
    int max = i;
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] > arr[max]) {
        max = j;
      }
    }
    if (arr[i] != arr[max]) {
      swap(&arr[i], &arr[max]);
    }
  }
}

int main() {
  int arr[] = {5, 4, 6, 1, 2, 3};
  selectionSort(arr, sizeof(arr) / sizeof(int));

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}