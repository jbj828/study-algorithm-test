#include <stdio.h>

void swap(int data[], int idx1, int idx2) {
  int temp = data[idx1];
  data[idx1] = data[idx2];
  data[idx2] = temp;
}

void quickSortUtil(int data[], int lower, int upper) {
  if (lower >= upper) {
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

int findMissingNumber(int data[], int size) {
  quickSort(data, size);

  for (int i = 0; i < size; i++) {
    if (data[i] != i + 1) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {8, 7, 5, 4, 9, 3, 2, 1};
  int missingNum = findMissingNumber(arr, sizeof(arr) / sizeof(int));
  printf("%d", missingNum);

  //   for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
  //     printf("%d ", arr[i]);
  //   }
  //   return 0;
}