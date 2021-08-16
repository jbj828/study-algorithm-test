#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//  public:
//   int findKthLargest(vector<int>& nums, int k) {
//     mergeSort(nums, 0, nums.size() - 1);

//     return nums.at(k);
//   }

//   void mergeSort(vector<int>& nums, int start, int end) {
//     if (start >= end) return;

//     int mid = (start + end) / 2;

//     mergeSort(nums, start, mid);
//     mergeSort(nums, mid + 1, end);

//   }
// };

// STL
// class Solution {
//  public:
//   int findKthLargest(vector<int>& nums, int k) {
//     nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),
//     greater<int>()); return nums[k - 1];
//   }
// };

// // QUICK SORT
// class Solution {
//  public:
//   int findKthLargest(vector<int>& nums, int k) {
//     int left = 0, right = nums.size() - 1, kth;
//     while (true) {
//       int idx = partition(nums, left, right);
//       if (idx == k - 1) {
//         kth = nums[idx];
//         break;
//       }
//       if (idx < k - 1) {
//         left = idx + 1;
//       } else {
//         right = idx - 1;
//       }
//     }
//     return kth;
//   }

//  private:
//   int partition(vector<int>& nums, int left, int right) {
//     int pivot = nums[left], l = left + 1, r = right;
//     while (l <= r) {
//       if (nums[l] < pivot && nums[r] > pivot) {
//         swap(nums[l++], nums[r--]);
//       }
//       if (nums[l] >= pivot) {
//         l++;
//       }
//       if (nums[r] <= pivot) {
//         r--;
//       }
//     }
//     swap(nums[left], nums[r]);
//     return r;
//   }
// };

class Solution {
 public:
  void quickSort(vector<int>& arr, int lb, int ub) {
    if (lb < ub) {
      int loc = partition(arr, lb, ub);
      quickSort(arr, lb, loc - 1);
      quickSort(arr, loc + 1, ub);
    }
  }

 private:
  int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[start];
    int l = start;
    int r = end;

    while (l < r) {
      while (arr[l] <= pivot) {
        l++;
      }
      while (arr[r] > pivot) {
        r--;
      }
      if (l < r) {
        swap(arr[l], arr[r]);
      }
    }
    swap(arr[start], arr[r]);
    return r;
  }
};