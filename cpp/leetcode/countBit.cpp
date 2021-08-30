#include <iostream>
#include <vector>

using namespace std;

// TC: O(n^2)
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ans;
    vector<int> cache;

    for (int i = 0; i <= n; i++) {
      int temp = i;
      int count = 0;
      if (i == 0 || i == 1) {
        ans.push_back(i);
        continue;
      }

      while (temp / 2 != 0) {
        if (temp % 2 == 1) count++;
        temp /= 2;
        if (temp == 1) count++;
      }
      ans.push_back(count);
    }

    return ans;
  }
};

// TC: O(n), Dynamic Programming
class Solution2 {
 public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);

    for (int i = 0; i <= n; i++) {
      if (i == 0) {
        ans[i] = i;
        continue;
      }

      if (i % 2 == 0) {
        ans[i] = ans[i / 2];
      } else {
        ans[i] = ans[i - 1] + 1;
      }
    }
    return ans;
  }
};