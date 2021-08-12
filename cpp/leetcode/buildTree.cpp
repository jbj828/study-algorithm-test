#include <iostream>
#include <unordered_map>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/*
  T.C : O(n^2)
*/
class Solution {
 private:
  int preInd = 0;

  TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int start,
                       int end) {
    if (start > end) {
      return NULL;
    }
    int pos;
    TreeNode* node = new TreeNode(preorder[preInd++]);
    for (int i = start; i <= end; i++) {
      if (inorder.at(i) == node->val) {
        pos = i;
        break;
      }
    }

    node->left = createTree(preorder, inorder, start, pos - 1);
    node->right = createTree(preorder, inorder, pos + 1, end);

    return node;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return createTree(preorder, inorder, 0, inorder.size() - 1);
  }
};

/*
  T.C: O(n)
  S.C: O(n)
*/

class Solution2 {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> M;
    for (int i = 0; i < inorder.size(); i++) {
      M[inorder[i]] = i;
    }
    return splitTree(preorder, M, 0, 0, inorder.size() - 1);
  }

 private:
  TreeNode* splitTree(vector<int>& P, unordered_map<int, int>& M, int pix,
                      int ileft, int iright) {
    int rval = P[pix], imid = M[rval];
    TreeNode* root = new TreeNode(rval);
    if (imid > ileft) {
      root->left = splitTree(P, M, pix++, ileft, imid - 1);
    }
    if (imid < iright) {
      root->right = splitTree(P, M, pix + imid - ileft + 1, imid + 1, iright);
    }
    return root;
  }
};