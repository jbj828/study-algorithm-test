#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int value) {
  // 오름차순으로 정렬된 배열에서 값을 찾는 알고리즘
  /*
      [1,2,3,4,5,6,7]  6

      인덱스를 반으로 나누어서 value가 중앙에 있는 인덱스보다 크면 오른쪽으로

  */

  int mid = (low + high) / 2;

  if (value > arr[mid]) {
    low = mid;
    return binarySearchRecursive(arr, low, high, value);
  } else if (value < arr[mid]) {
    high = mid;
    return binarySearchRecursive(arr, low, high, value);
  } else {
    return mid;
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("%d", binarySearchRecursive(arr, 0, sizeof(arr) / sizeof(int) - 1, 3));
  return 0;
}