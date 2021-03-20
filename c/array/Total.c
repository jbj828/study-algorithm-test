#include <stdio.h>

int total(int* arr) {
  int result;
  int total = 0;

  int size = sizeof(arr) / sizeof(int);

  for (int i = 0; i < size; i++) {
    total += arr[i];
  }
  return total;
}