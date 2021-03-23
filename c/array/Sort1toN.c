#include <stdio.h>

void Sort1toN(int arr[], int size) {
  int curr, value, next;
  for(int i = 0; i < size; i++){
      curr = i;
      value = -1;
      while(curr >= 0 && curr < size && arr[curr] != curr + 1){
          next = arr[curr];
          arr[curr] = value;
          value = next;
          curr = next - 1;
      }
  }
}

int main() {
  int arr[] = {5, 3, 1, 2, 4};
  int size = sizeof(arr) / sizeof(int);
  Sort1toN(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}