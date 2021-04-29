#include <stdio.h>

// 퀵정렬이 가장 적은 횟수로 정렬이 가능하다. 이번 문제의 경우에도 퀵정렬
// 방식으로 진행하면 된다.

int minSwaps(int arr[], int size, int val) {
  int left = 0;
  int right = size - 1;
  int count = 0;

  while (left < right) {
    if (arr[left] <= val) {
      left++;
    } else if (arr[right] > val) {
      right--;
    } else {
      swap(arr, left, right);
      count++;
    }
  }

  return count;
}
