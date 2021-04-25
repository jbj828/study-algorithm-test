int more(int value1, int value2) { return value1 > value2; }

void swap(int* value1, int* value2) {
  int temp;

  temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}
/*
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
void BubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (more(arr[j], arr[j + 1])) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}