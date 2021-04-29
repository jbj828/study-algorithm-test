#include <stdio.h>

void partition012(int arr[], int size) {
  int countZero = 0, countOne = 0, countTwo = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) {
      countZero++;
    }
    if (arr[i] == 1) {
      countOne++;
    }
    if (arr[i] == 2) {
      countTwo++;
    }
  }

  for (int i = 0; i < size; i++) {
    if (i < countZero) {
      arr[i] = 0;
    }
    if (i >= countZero && i < countZero + countOne) {
      arr[i] = 1;
    }
    if (i >= countZero + countOne && i < countZero + countOne + countTwo) {
      arr[i] = 2;
    }
  }
}

void partition012Better(int arr[], int size) {
  int left = 0;
  int right = size - 1;
  int i = 0;

  while (i <= right) {
    if (arr[i] == 0) {
      swap(arr, i, left);
      i++;
      left++;
    } else if (arr[i] == 2) {
      swap(arr, i, right);
      right--;
    } else {
      i++;
    }
  }
}

int main() {
  int arr[] = {0, 1, 1, 0, 2, 0, 2, 0, 2, 1, 2, 1, 0};
  partition012(arr, sizeof(arr) / sizeof(int));

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}