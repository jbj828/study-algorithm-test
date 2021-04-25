/*
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
void insertionSort(int arr[], int size) {
  int temp, j;

  for (int i = 1; i < size; i++) {
    temp = arr[i];
    for (j = i; j > 0 && more(arr[j - 1], arr[j]); j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;
  }
}