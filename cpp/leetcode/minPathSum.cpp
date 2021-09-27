#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > cache;
  int sum = 9000000;
  int helper(int x, int y, int m, int n, const vector<vector<int> >& grid) {
    // base case
    if (x == m - 1 && y == n - 1) return grid[y][x];

    if (x >= m || y >= n) return 0;

    // 조각
    // 옆 이동
    int go_next = grid[y][x] + helper(x + 1, y, m, n, grid);
    int go_bottom = grid[y][x] + helper(x, y + 1, m, n, grid);

    return min(go_next, go_bottom);
  }

  int minPathSum(vector<vector<int> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    return helper(0, 0, m, n, grid);
  }
};