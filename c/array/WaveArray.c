#include <stdio.h>

#define LENGTH 6

void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/*
    Time Complexity : O(n^2)
*/
void WaveArray(int arr[], int size) {
  for (int i = 0; i < size; i += 2) {
    for (int j = 0; j < size; j += 2) {
      if (j != 0) {
        if (arr[j] < arr[j - 1]) {
          swap(&arr[i], &arr[i - 1]);
        }
      }
      if (j != size - 1) {
        if (arr[j] < arr[j + 1]) {
          swap(&arr[i], &arr[i + 1]);
        }
      }
    }
  }
}

/*
    Time Complexity : O(n)
*/
void WaveArray2(int arr[], int size) {
  for (int i = 1; i < size; i += 2) {
    if ((i - 1) >= 0 && arr[i] > arr[i - 1]) {
      swap(&arr[i], &arr[i - 1]);
    }
    if ((i + 1) < size && arr[i] > arr[i + 1]) {
      swap(&arr[i], &arr[i + 1]);
    }
  }
}

int main() {
  int arr[LENGTH] = {1, 2, 3, 4, 5, 6};
  WaveArray(arr, LENGTH);

  for (int i = 0; i < LENGTH; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

/*
    배열 문제는 눈에 잘보이지 않으면 한 번 정렬을 진행해보고 생각해보자!
*/