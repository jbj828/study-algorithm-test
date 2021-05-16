/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  nums.sort((a, b) => a - b);

  for (let i = 1; i < nums.length; i++) {
    if (nums[i] - nums[i - 1] <= 0) {
      return true;
    }
  }
  return false;
};
