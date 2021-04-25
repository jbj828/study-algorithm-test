#include <stdio.h>

int more(int value1, int value2) { return value1 > value2; }

void swap(int* value1, int* value2) {
  int temp;

  temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

// 일부 원소를 제외한 배열의 나머지 부분이 이미 정렬된 상태임을 알고 있다면
// 향상된 버블 정렬이 유용하다 최선의 시간 복잡도는 O(n)이 된다.
void BubbleSort2(int arr[], int size) {
  int swapped = 1;
  for (int i = 0; i < (size - 1) && swapped; i++) {
    swapped = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (more(arr[j], arr[j + 1])) {
        swap(&arr[j], &arr[j + 1]);
        swapped = 1;
      }
    }
  }
}

int main() {
  int arr[] = {5, 4, 6, 1, 2, 3};
  BubbleSort2(arr, sizeof(arr) / sizeof(int));

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}