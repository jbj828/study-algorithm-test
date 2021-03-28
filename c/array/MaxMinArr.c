#include <stdio.h>
#include <stdlib.h>

// 보조 배열로 입력 배열의 복사본을 만든다. 이후 입력 배열을 처음부터 끝까지
// 순회하며 값들 바꿔넣는다 여기서 내가 실수한 부분은 각 인덱스에서 1씩 더하거나
// 빼야되는데, i만큼 더하거나 빼면 된다고 생각한 부분이다. i 만큼 더하거나 빼면
// i 의 수는 2의 배수로 늘어나기 때문에 우리가 기대하는 값, 즉 1씩 감소하거나
// 증가하는 인덱스를 얻을 수 없다.
// time complexity: O(n), space complexity: O(n)
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

void ReverseArr(int arr[], int start, int stop) {
  while (start < stop) {
    int temp = arr[start];
    arr[start] = arr[stop];
    arr[stop] = temp;
    start++;
    stop--;
  }
}

// time complexity: O(n^2), space complexity: O(1)
void MaxMinArr2(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    ReverseArr(arr, i, size - 1);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(int);
  MaxMinArr2(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}