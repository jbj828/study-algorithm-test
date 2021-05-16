/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
  if (!nums.length) return null;

  const center = Math.floor(nums.length / 2);
  const node = new TreeNode(nums[center]);
  node.left = sortedArrayToBST(nums.slice(0, center));
  node.right = sortedArrayToBST(nums.slice(center + 1));

  return node;
};
