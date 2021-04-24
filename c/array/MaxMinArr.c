#include <stdio.h>
#include <stdlib.h>

//
void MaxMinArr(int arr[], int size) {
  int* aux = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    aux[i] = arr[i];
  }

  int start = 0;
  int stop = size - 1;
  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      arr[i] = aux[stop];
      stop--;
    } else {
      arr[i] = aux[start];
      start++;
    }
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(int);
  MaxMinArr(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}