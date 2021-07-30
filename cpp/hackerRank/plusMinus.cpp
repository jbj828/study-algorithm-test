#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
  double plus = 0.0, minus = 0.0, zero = 0.0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr.at(i) > 0) plus++;
    if (arr.at(i) < 0) minus++;
    if (arr.at(i) == 0) zero++;
  }

  double plus_ratio = (plus / arr.size()) * pow(10, 6);
  double minus_ratio = (minus / arr.size()) * pow(10, 6);
  double zero_ratio = (zero / arr.size()) * pow(10, 6);

  cout << plus_ratio << endl;
  cout << minus_ratio << endl;
  cout << zero_ratio << endl;

  //   double plus_ratio_d = plus_ratio * pow(10, -6);
  //   double minus_ratio_d = minus_ratio * pow(10, -6);
  //   double zero_ratio_d = zero_ratio * pow(10, -6);

  //   cout << plus_ratio_d << endl;
  //   cout << minus_ratio_d << endl;
  //   cout << zero_ratio_d << endl;
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  plusMinus(arr);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
