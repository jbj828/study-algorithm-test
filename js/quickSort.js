function quickSort(arr) {
  quickSortUtil(arr, 0, arr.length - 1);
}

function quickSortUtil(arr, l, r) {
  if (l >= r) return;
  let p = partition(arr, l, r);

  quickSortUtil(arr, l, p - 1);
  quickSortUtil(arr, p + 1, r);
}

function partition(arr, l, r) {
  const pivot = arr[r];
  let i = l - 1;
  for (let j = l; j < r; j++) {
    if (arr[j] < pivot) {
      i++;
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }
  [arr[i + 1], arr[r]] = [arr[r], arr[i + 1]];

  return i + 1;
}
