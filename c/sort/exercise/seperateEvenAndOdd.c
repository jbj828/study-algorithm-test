#include <stdio.h>

void seperateEvenAndOdd(int data[], int size) {
  int left = 0, right = size - 1;
  while (left < right) {
    if (data[left] % 2 == 0) {
      left++;
    } else if (data[right] % 2 == 1) {
      right--;
    } else {
      swap(data, left, right);
      left++;
      right--;
    }
  }
}