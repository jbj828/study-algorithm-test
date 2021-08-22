#include <iostream>
#include <queue>

using namespace std;

int main() {
  // Max Heap
  priority_queue<int, vector<int>, less<int> > pq1;

  pq1.push(5);
  pq1.push(2);
  pq1.push(8);
  pq1.push(9);
  pq1.push(1);
  pq1.push(14);

  pq1.pop();
  pq1.pop();

  while (!pq1.empty()) {
    cout << pq1.top() << " ";
    pq1.pop();
  }
  cout << endl;

  // Min Heap
  priority_queue<int, vector<int>, greater<int> > pq2;

  pq2.push(5);
  pq2.push(2);
  pq2.push(8);
  pq2.push(9);
  pq2.push(1);
  pq2.push(14);

  pq2.pop();
  pq2.pop();

  while (!pq2.empty()) {
    cout << pq2.top() << " ";
    pq2.pop();
  }
  cout << endl;
}