#include <stdio.h>
#include <stdlib.h>

void absBubbleSort(int arr[], int size, int ref) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      int absCriteria = abs(ref - arr[j]);
      int absTarget = abs(ref - arr[j + 1]);
      if (absCriteria > absTarget) {
        swap(arr, j, j + 1);
      }
    }
  }
}