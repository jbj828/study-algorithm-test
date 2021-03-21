#include <stdio.h>

void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/*
    Time Complexity : O(n)

    선택된 인덱스의 값을 -1로 만들고, 선택된 인덱스의 값과 같은 인덱스에 값을
   넣는다.
*/
void indexArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int curr = i;
    int value = -1;

    while (arr[curr] != -1 && arr[curr] != curr) {
      int temp = arr[curr];
      arr[curr] = value;
      value = curr = temp;
    }

    if (value != -1) {
      arr[curr] = value;
    }
  }
}

/*
    Time Complexity : O(n)
*/
void indexArray2(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    while (arr[i] != 1 && arr[i] != i) {
      int temp = arr[i];
      arr[i] = arr[temp];
      arr[temp] = temp;
    }
  }
}