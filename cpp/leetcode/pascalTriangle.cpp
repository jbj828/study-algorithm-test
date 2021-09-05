#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;

    for (int i = 0; i < numRows; i++) {
      vector<int> tempArr(i + 1);

      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          tempArr[j] = 1;
          continue;
        }
        tempArr[j] = result[i - 1][j - 1] + result[i - 1][j];
      }
      result.push_back(tempArr);
    }

    return result;
  }
};