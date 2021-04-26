#include <stdio.h>
#include <stdlib.h>

/*
    퀵 정렬은 매우 적은 공간을 사용하며, O(logn)의 추가 공간만 필요하다. 퀵
   정렬은 동일한 키의 원소를 다른 위치에 정렬할 수 있기 때문에 안정 정렬이
   아니다.

    time: 최악 - O(n^2), 평균, 최선 - O(nlogn)
    space: O(logn)
*/

void quickSortUtil(int* arr, int lower, int upper) {
  if (upper <= lower) return;

  int pivot = arr[lower];
  int start = lower;
  int stop = upper;

  while (lower < upper) {
    while (arr[lower] <= pivot) {
      lower++;
    }
    while (arr[upper] > pivot) {
      upper--;
    }
    if (lower < upper) {
      swap(arr, upper, lower);
    }
  }

  swap(arr, upper, start);
  quickSortUtil(arr, start, upper - 1);
  quickSortUtil(arr, upper + 1, stop);
}

void quickSort(int arr[], int size) {
  // 1. 처음에 배열의 첫번째 값을 가지는 변수를 설정, 그 다음 값을 L, 마지막
  // 값을 U
  // 2. L가 피벗보다 작으면 다음 인덱스로 이동, L가 피벗보다 크면 U랑 피벗을
  // 비교시작
  // 3. U가 피벗보다 크면 다음으로 이동, U가 피벗보다 작으면 L과 U를 교환
  // 4. 상위 인덱스가 하위 인덱스보다 크면 위의 것을 반복한다.
  // 5. 끝으로 상위 인덱스와 피벗을 교환한다.

  quickSortUtil(arr, 0, size - 1);
}