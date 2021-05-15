/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
  let i = 0;
  let count = 0;
  for (let j = 0; j < nums.length; j++) {
    if (nums[j] === 0 && count === 0) {
      i = j;
      count++;
    }
    if (nums[j] !== 0) {
      [nums[i], nums[j]] = [nums[j], nums[i]];
      i++;
    }
  }
};

// same solution, better code quality
var moveZeroes = function (nums) {
  let idx = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      nums[idx++] = nums[i];
    }
  }
  for (let i = idx; i < nums.length; i++) {
    nums[i] = 0;
  }
};
