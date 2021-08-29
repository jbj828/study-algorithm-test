#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool jumpRecursive(const vector<vector<int> >& table, const size_t size, int x,
                   int y) {
  int lastIndex = size - 1;
  if (x > lastIndex || y > lastIndex) return false;
  if (x == lastIndex && y == lastIndex) return true;

  int value = table[x][y];
  return jumpRecursive(table, size, x + value, y) ||
         jumpRecursive(table, size, x, y + value);
}

bool jump(const vector<vector<int> >& table) {
  size_t size = table.size();
  return jumpRecursive(table, size, 0, 0);
}

// Dynamic Programming
int n, table[100][100];
int cache[100][100];
int jump2(int x, int y) {
  if (x >= n || y >= n) return 0;
  if (x == n - 1 && y == n - 1) return 1;

  int& ret = cache[x][y];
  if (ret != -1) return ret;

  int jumpSize = table[x][y];
  return ret = (jump2(x + jumpSize, y) || jump2(x, y + jumpSize));
}

int main() {
  vector<vector<int> > table;
  vector<int> v1;
  v1.push_back(2);
  v1.push_back(5);
  v1.push_back(1);
  v1.push_back(6);
  v1.push_back(1);
  v1.push_back(4);
  v1.push_back(1);

  vector<int> v2;
  v2.push_back(6);
  v2.push_back(1);
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(2);
  v2.push_back(9);
  v2.push_back(3);

  vector<int> v3;
  v3.push_back(7);
  v3.push_back(2);
  v3.push_back(3);
  v3.push_back(2);
  v3.push_back(1);
  v3.push_back(3);
  v3.push_back(1);

  vector<int> v4;
  v4.push_back(1);
  v4.push_back(1);
  v4.push_back(3);
  v4.push_back(1);
  v4.push_back(7);
  v4.push_back(1);
  v4.push_back(2);

  vector<int> v5;
  v5.push_back(4);
  v5.push_back(1);
  v5.push_back(2);
  v5.push_back(3);
  v5.push_back(4);
  v5.push_back(1);
  v5.push_back(2);

  vector<int> v6;
  v6.push_back(3);
  v6.push_back(3);
  v6.push_back(1);
  v6.push_back(2);
  v6.push_back(3);
  v6.push_back(4);
  v6.push_back(1);

  vector<int> v7;
  v7.push_back(1);
  v7.push_back(5);
  v7.push_back(2);
  v7.push_back(9);
  v7.push_back(4);
  v7.push_back(7);
  v7.push_back(0);

  table.push_back(v1);
  table.push_back(v2);
  table.push_back(v3);
  table.push_back(v4);
  table.push_back(v5);
  table.push_back(v6);
  table.push_back(v7);

  bool result = jump(table);
  string resultStr = result ? "success" : "failed";
  cout << resultStr << endl;
}