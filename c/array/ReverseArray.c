void resverseArray(int* a, int n) {
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    a[i] ^= a[j] ^= a[i] ^= a[j];
  }
}

void rotateArray2(int* a, int n, int k) {
  resverseArray(a, k);
  resverseArray(&a[k], n - k);
  resverseArray(a, n);
}