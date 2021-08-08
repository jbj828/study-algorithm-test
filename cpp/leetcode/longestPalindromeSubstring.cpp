#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;

    int max_size = -1;
    string longest_str = "";

    for (int i = 0; i < s.size(); ++i) {
      int left, right, temp_size;

      // jkkj
      if (i - 1 >= 0 && i + 1 < s.size() && s.at(i - 1) == s.at(i + 1) &&
          s.at(i) != s.at(i + 1)) {
        left = i - 1;
        right = i + 1;
        temp_size = 3;
      } else if (i - 1 >= 0 && i + 1 < s.size() && s.at(i) == s.at(i + 1) &&
                 s.at(i - 1) != s.at(i + 1)) {
        left = i;
        right = i + 1;
        temp_size = 2;
      } else {
        continue;
      }

      while (left - 1 >= 0 && right + 1 < s.size() &&
             s.at(left - 1) == s.at(right + 1)) {
        temp_size += 2;
        --left;
        ++right;
      }
      if (temp_size > max_size) {
        max_size = temp_size;
        longest_str = s.substr(left, temp_size);
      }
    }

    if (longest_str.empty()) return s.substr(0, 1);

    return longest_str;
  }
};

// 올바른 답
string longestPalindrome(string s) {
  // edge cases
  if (s.length() <= 1) return s;

  int maxLenBeginIndex = 0;
  int maxLen = 1;

  int mid = 0;
  while (mid < s.length()) {
    int midBegin = mid;
    int midEnd = mid;

    while (midEnd + 1 < s.length() && s[midEnd] == s[midEnd + 1]) {
      midEnd++;
    }

    mid = midEnd + 1;

    int leftWindow = midBegin;
    int rightWindow = midEnd;

    while (leftWindow - 1 >= 0 && rightWindow + 1 < s.length() &&
           s[leftWindow - 1] == s[rightWindow + 1]) {
      leftWindow--;
      rightWindow++;
    }

    int currLen = rightWindow - leftWindow + 1;
    if (currLen > maxLen) {
      maxLenBeginIndex = leftWindow;
      maxLen = currLen;
    }
  }

  return s.substr(maxLenBeginIndex, maxLen);
}