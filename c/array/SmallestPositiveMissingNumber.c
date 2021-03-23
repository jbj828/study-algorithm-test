#include <stdio.h>
#include <stdlib.h>

// Brute force
// time Complexity:  O(n^2)

int SmallestPositiveMissingNumber(int arr[], int size) {
  int found;
  for (int i = 1; i < size + 1; i++) {
    found = 0;
    for (int j = 0; j < size; j++) {
      if (arr[j] == i) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      return i;
    }
  }
  return -1;
}

// Hash Table
// time complexity:  O(n), space complexity: O(n) -> because of hash table is
// exist
int SmallestPositiveMissingNumber2(int arr[], int size) {
  HashTable hs;
  for (int i = 0; i < size; i++) {
    HashAdd(&hs, arr[i])
  }
  for (int i = 1; i < size + 1; i++) {
    if (!HashFind(hs, i)) {
      return i;
    }
  }
  return -1;
}

//  값을 보조 배열에 저장한다.
// time complexity:  O(n), space complexity: O(n)
int SmallestPositiveMissingNumber3(int arr[], int size) {
  int* aux = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    if (arr[i] > 0 && arr[i] <= size) {
      aux[arr[i] - 1] = arr[i];
    }
  }
  for (int i = 0; i < size; i++) {
    if (aux[i] != i + 1) {
      return i + 1;
    }
  }
  return -1;
}

// 배열의 원소를 재배치한다. 원소를 재배치해 선형 시간에 상수 공간 복잡도를
// 가지는 원소를 찾을 수 있다. time complexity : O(n), space complexity: O(1)
int SmallestPositiveMissingNumber4(int arr[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    while (arr[i] != i + 1 && arr[i] > 0 && arr[i] <= size) {
      temp = arr[i];
      arr[i] = arr[temp - 1];
      arr[temp - 1] = temp;
    }
  }
  for (int i = 0; i < size; i++) {
    if (arr[i] != i + 1) {
      return i + 1;
    }
  }
  return -1;
}
