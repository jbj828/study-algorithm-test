#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.empty()) return true;

    int pos = 0;
    for (int i = 0; i < t.size(); i++) {
      if (t.at(i) == s.at(pos)) {
        if (pos == s.size() - 1) return true;
        pos++;
      }
    }
    return false;
  }
};