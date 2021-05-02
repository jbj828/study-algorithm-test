

int binarySearch(int data[], int size, int value) {
  int low = 0, high = size - 1, mid;

  while (low < high) {
    mid = (low + high) / 2;

    if (data[mid] == value) {
      return 1;
    } else if (data[mid] > value) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return 0;
}

int binarySearchRecursive(int data[], int size, int low, int high, int value) {
  if (low > high) {
    return 0;
  }

  int mid = (low + high) / 2;

  if (data[mid] == value) {
    return 1;
  }
  if (data[mid] > value) {
    return binarySearchRecursive(data, size, low, mid - 1, value);
  }
  if (data[mid] < value) {
    return binarySearchRecursive(data, size, mid + 1, high, value);
  }
}