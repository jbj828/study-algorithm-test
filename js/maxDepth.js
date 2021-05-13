/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
  if (!root) {
    return 0;
  }

  // 결국 tree는 recursion으로 깊이 혹은 traversal을 계산할 수 있다.
  // 재귀를 사용할 경우 새로운 handler 함수를 만들어서 재귀 처리를 하는게 로직 처리를 하는데 도움이 된다.

  return maxDepthHandler(root, 1);
};

function maxDepthHandler(root, count) {
  // 종료조건은 leaf node에 자식이 더 이상 없을 때이다. 이때 count 를 반환하면 된다.
  if (!root.left && !root.right) {
    return count;
  }

  if (root.left && root.right) {
    return Math.max(
      maxDepthHandler(root.left, count + 1),
      maxDepthHandler(root.right, count + 1)
    );
  } else if (root.left !== null) {
    return maxDepthHandler(root.left, count + 1);
  } else {
    return maxDepthHandler(root.right, count + 1);
  }
}
