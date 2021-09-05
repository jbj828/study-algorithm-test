#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int> > pascalArr;

    for (int i = 0; i <= rowIndex; i++) {
      vector<int> tempArr(i + 1);

      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          tempArr[j] = 1;
          continue;
        }
        tempArr[j] = pascalArr[i - 1][j - 1] + pascalArr[i - 1][j];
      }
      pascalArr.push_back(tempArr);
    }

    return pascalArr[rowIndex];
  }
};