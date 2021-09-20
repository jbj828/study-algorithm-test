#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int dp[38] = {0, 1, 1, 2};
  int tribonacci(int n) {
    for (int i = 4; i <= n; i++) {
      dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    return dp[n];
  }
};