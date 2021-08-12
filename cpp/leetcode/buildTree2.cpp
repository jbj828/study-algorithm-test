#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */

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
 private:
  int postIdx;

  TreeNode *createTree(vector<int> &inorder, vector<int> &postorder, int start,
                       int end) {
    if (start > end) return NULL;

    TreeNode *node = new TreeNode(postorder.at(postIdx--));
    int pos;
    for (int i = start; i <= end; i++) {
      if (inorder[i] == node->val) {
        pos = i;
        break;
      }
    }

    node->right = createTree(inorder, postorder, pos + 1, end);
    node->left = createTree(inorder, postorder, start, pos - 1);

    return node;
  }

 public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    postIdx = postorder.size() - 1;
    return createTree(inorder, postorder, 0, inorder.size() - 1);
  }
};