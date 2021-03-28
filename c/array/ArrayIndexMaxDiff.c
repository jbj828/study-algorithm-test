#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

int ArrayIndexMaxDiff(int arr[], int size) {
  int diff = 0;
  int indexA, indexB;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (abs(arr[j] - arr[i]) > diff) {
        diff = abs(arr[j] - arr[i]);
        indexA = j;
        indexB = i;
      }
    }
  }
  return abs(indexA - indexB);
}

int ArrayIndexMaxDiff2(int arr[], int size) {
  int *leftMin = (int *)malloc(sizeof(int) * size);
  int *rightMax = (int *)malloc(sizeof(int) * size);
  leftMin[0] = arr[0];
  int i, j;
  int maxDiff;

  for (i = 1; i < size; i++) {
    if (leftMin[i - 1] < arr[i]) {
      leftMin[i] = leftMin[i - 1];
    } else {
      leftMin[i] = arr[i];
    }
  }

  rightMax[size - 1] = arr[size - 1];
  for (i = size - 2; i >= 0; i--) {
    if (rightMax[i + 1] > arr[i]) {
      rightMax[i] = rightMax[i + 1];
    } else {
      rightMax[i] = arr[i];
    }
  }

  i = 0;
  j = 0;
  maxDiff = -1;
  while (j < size && i < size) {
    if (leftMin[i] < rightMax[j]) {
      maxDiff = max(maxDiff, j - i);
      j = j + 1;
    } else {
      i = i + 1;
    }
  }
  return maxDiff;
}

int main() {
  int arr[] = {50, 9, 8, 30, 6};
  printf("%d", ArrayIndexMaxDiff2(arr, sizeof(arr) / sizeof(int)));
}