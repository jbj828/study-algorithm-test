#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cutFence(vector<int>& arr) {
  int area = -1;

  for (int i = 0; i < arr.size(); i++) {
    int min_height = arr[i];
    for (int j = i; j < arr.size(); j++) {
      min_height = min(min_height, arr[j]);
      area = max(min_height * (j - i + 1), area);
    }
  }
  return area;
}

int main() {
  vector<int> arr;

  arr.push_back(1);
  arr.push_back(8);
  arr.push_back(2);
  arr.push_back(2);
  //   arr.push_back(4);
  //   arr.push_back(1);
  //   arr.push_back(1);

  int result = cutFence(arr);
  cout << result << endl;
}
