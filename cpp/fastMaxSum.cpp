#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fastMaxSum(const vector<int> &A, int low, int high)
{
    if (low == high)
        return A[low];
    int mid = (low + high) / 2;
    int left = INT_MIN, right = INT_MIN, sum = 0;

    for (int i = mid; i >= low; --i)
    {
        sum += A[i];
        left = max(sum, left);
    }

    sum = 0;
    for (int j = mid + 1; j <= high; ++j)
    {
        sum += A[j];
        right = max(sum, right);
    }

    int single = max(fastMaxSum(A, low, mid), fastMaxSum(A, mid + 1, high));
    return max(left + right, single);
}

int main()
{
    vector<int> A{1, 2, 3, 4, 5};
    int result = fastMaxSum(A, 0, A.size() - 1);
    std::cout << result << std::endl;
    return 0;
}