#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//  public:
//   bool searchMatrix(vector<vector<int> >& matrix, int target) {
//     bool result = false;
//     for (int i = 0; i < matrix.size(); i++) {
//       result = _searchMatrix(matrix[i], target, 0, matrix[i].size() - 1);
//       if (result) break;
//     }
//     return result;
//   }

//  private:
//   bool _searchMatrix(vector<int>& matrix, int target, int start, int end) {
//     if (start >= end) return false;

//     int mid = matrix.size() / 2;
//     int midVal = matrix.at(mid);

//     if (midVal > target) {
//       end = midVal - 1;
//     } else if (midVal < target) {
//       start = midVal + 1;
//     } else {
//       return true;
//     }
//     return _searchMatrix(matrix, target, start, end);
//   }
// };

class Solution {
 public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int row = 0, col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0) {
      if (target == matrix[row][col]) return true;

      target > matrix[row][col] ? row++ : col--;
    }
    return false;
  }
};