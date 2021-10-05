#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int helper(int x, int y, int m, int n, const vector<vector<int> >& grid,
             vector<vector<int> >& cache) {
    // base case
    if (x == m - 1 && y == n - 1) return grid[y][x];

    if (x >= m || y >= n) {
      return 900000;
    }

    if (cache[y][x] != -1) return cache[y][x];

    // 조각
    int go_next = grid[y][x] + helper(x + 1, y, m, n, grid, cache);
    int go_bottom = grid[y][x] + helper(x, y + 1, m, n, grid, cache);

    return cache[y][x] = min(go_next, go_bottom);
  }

  int minPathSum(vector<vector<int> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > cache(n, vector<int>(m, -1));
    return helper(0, 0, m, n, grid, cache);
  }
};