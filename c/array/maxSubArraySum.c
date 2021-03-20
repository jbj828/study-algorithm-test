#include <stdio.h>

// My answer, TimeComplexity : O(n^2)
int maxSubArraySum2(int a[], int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += a[i];
  }
  for (int i = 0; i < size; i++) {
    int tempSum = a[i];
    for (int j = i + 1; j < size; j++) {
      tempSum += a[j];
      if (tempSum > sum) {
        sum = tempSum;
      }
    }
  }
  return sum;
}

// Better answer, TimeComplexity: O(n)
int maxSubArraySum(int a[], int size) {
  int maxSoFar = 0, maxEndingHere = 0;
  for (int i = 0; i < size; i++) {
    maxEndingHere += a[i];
    if (maxEndingHere < 0) {
      maxEndingHere = 0;
    }
    if (maxSoFar < maxEndingHere) {
      maxSoFar = maxEndingHere;
    }
  }
  return maxSoFar;
}

int main() {
  int a[] = {1, 2, -4, 5, 9, -3};
  int size = sizeof(a) / sizeof(int);
  int result = maxSubArraySum(a, size);
  printf("%d", result);

  return 0;
}