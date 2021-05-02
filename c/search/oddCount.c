#include <stdio.h>
#include <stdlib.h>

void oddCount(int data[], int size) {
  int temp = data[0];
  for (int i = 1; i < size; i++) {
    temp ^= data[i];
  }
  printf("%d", temp);
}

void oddCount2(int data[], int size) {
  Counter ctr;
  CounterInit(&ctr);
  int count;
  for (int i = 0; i < size; i++) {
    CounterAdd(&ctr, data[i]);
  }
  for (int i = 0; i < size; i++) {
    count = CounterGetCount(&ctr, data[i]);
    if (count > 0 && (count % 2 == 1)) {
      printf("%d", count);
      CounterDelete(&ctr, data[i]);
    }
  }
}

int main() {
  int arr[] = {8, 7, 8, 3, 7, 3, 2};
  oddCount(arr, sizeof(arr) / sizeof(int));

  //   for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
  //     printf("%d ", arr[i]);
  //   }
  //   return 0;
}