/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    if (!head->next) {
      TreeNode *node = new TreeNode(head->val);
      return node;
    }
    ListNode *mid = getMid(head);
    TreeNode *node = new TreeNode(mid->val);

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);

    return node;
  }

  ListNode *getMid(ListNode *head) {
    ListNode *prevMid = nullptr;

    while (head && head->next) {
      prevMid = prevMid ? prevMid->next : head;
      head = head->next->next;
    }

    ListNode *mid = prevMid->next;
    prevMid->next = nullptr;

    return mid;
  }
};