#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bucketSort(int arr[], int size) {
  // 1. 인자는 0으로 채워넣은 같이 길이의 배열을 하나 만든다.
  // 2. 새 배열의 인덱스와 같은 숫자가 나오면 값을 1 증가시킨다.
  // 3. 새 배열을 반복문으로 돌면서 값을 바꿔나간다.

  int* bucket = (int*)malloc(size * sizeof(int));
  memset(bucket, 0, size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bucket[arr[i]]++;
  }

  int val = 0;
  for (int i = 0; i < size; i++) {
    for (int j = val; j < val + bucket[i]; j++) {
      arr[j] = i;
    }
    val += bucket[i];
  }

  free(bucket);
}

int main() {
  int arr[] = {5, 4, 0, 1, 2, 3};
  bucketSort(arr, sizeof(arr) / sizeof(int));

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}