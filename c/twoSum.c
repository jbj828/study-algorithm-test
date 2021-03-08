/*
    Brute force
        Time : O(n^2)
        Space : O(1)
*/

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *returnValues = malloc((*returnSize) * sizeof(int));

  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        returnValues[0] = i;
        returnValues[1] = j;
        break;
      }
    }
  }

  return returnValues;
}
