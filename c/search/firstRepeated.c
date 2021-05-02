#include <stdio.h>

void quickSortUtil(int data[], int lower, int upper) {
  if (upper <= lower) {
    return;
  }
  int pivot = data[lower];
  int start = lower;
  int stop = upper;

  while (lower < upper) {
    while (data[lower] <= pivot) {
      lower++;
    }
    while (data[upper] > pivot) {
      upper--;
    }
    if (lower < upper) {
      swap(data, lower, upper);
    }
  }

  swap(data, upper, start);
  quickSortUtil(data, start, upper - 1);
  quickSortUtil(data, upper + 1, stop);
}

void quickSort(int data[], int size) { quickSortUtil(data, 0, size - 1); }

int firstRepeated(int data[], int size) {
  quickSort(data, size);

  for (int i = 0; i < size; i++) {
    if (data[i] == data[i + 1]) {
      return data[i];
    }
  }
  return -1;
}