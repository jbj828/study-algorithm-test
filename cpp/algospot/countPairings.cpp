#include <iostream>

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
  int firstFree = -1;
  for (int i = 0; i < n; ++i) {
    if (!taken[i]) {
      firstFree = i;
      break;
    }
  }
  // 기저조건
  if (firstFree == -1) return 1;

  int ret;
  for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
    if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
      taken[firstFree] = taken[pairWith] = true;
      ret += countPairings(taken);
      taken[firstFree] = taken[pairWith] = false;
    }
  }
  return ret;
}