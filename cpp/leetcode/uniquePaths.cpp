#include <iostream>
#include <vector>

using namespace std;

// Recursive
class Solution {
 public:
  int helper(int m, int n, int x, int y) {
    if (x == m - 1 && y == n - 1) {
      return 1;
    }
    if (x >= m || y >= n) {
      return 0;
    }

    return helper(m, n, x + 1, y) + helper(m, n, x, y + 1);
  }

  int uniquePaths(int m, int n) { return helper(m, n, 0, 0); }
};

// Recursive + Memoization
class Solution {
 public:
  int helper(int m, int n, int x, int y, vector<vector<int> >& cache) {
    if (x == m - 1 && y == n - 1) return 1;
    if (x >= m || y >= n) return 0;
    if (cache[x][y] != -1) return cache[x][y];

    return cache[x][y] =
               helper(m, n, x + 1, y, cache) + helper(m, n, x, y + 1, cache);
  }

  int uniquePaths(int m, int n) {
    vector<vector<int> > cache(m, vector<int>(n, -1));
    return helper(m, n, 0, 0, cache);
  }
};