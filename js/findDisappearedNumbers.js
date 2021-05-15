/**
 * @param {number[]} nums
 * @return {number[]}
 */
/*
    TC: O(n)
    SC: O(n)
*/

var findDisappearedNumbers = function (nums) {
  const result = [];
  const counts = new Array(nums.length + 1).fill(1);

  nums.forEach((num) => {
    counts[num]--;
  });

  counts.forEach((count, idx) => {
    if (count === 1) {
      result.push(idx);
    }
  });
  return result.slice(1);
};

/*
    TC: O(n)
    SC: O(1)
*/
var findDisappearedNumbers = function (nums) {
  const result = [];

  for (let i = 0; i < nums.length; i++) {
    let num = Math.abs(nums[i]);
    let idx = nums[i] - 1;
    nums[idx] = Math.abs(nums[idx]) * -1;
  }
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) result.push(i + 1);
  }
  return result;
};
