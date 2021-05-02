#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printRepeating(int data[], int size) {
  int* count = (int*)malloc(sizeof(int) * size);
  memset(count, 0, sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    if (count[data[i]] == 1) {
      printf(" %d ", data[i]);
    } else {
      count[data[i]]++;
    }
  }
}