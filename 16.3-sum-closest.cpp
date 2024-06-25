/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.87%)
 * Likes:    10398
 * Dislikes: 563
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 =
 * 0).
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 500
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    // result of three sum closest
    // initially we set it as first three element sum
    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); ++i) {
      int ptr1 = i + 1, ptr2 = nums.size() - 1;
      while (ptr1 < ptr2) {
        const int currentSum = nums[i] + nums[ptr1] + nums[ptr2];
        if (currentSum == target) {
          return target;
        } else if (currentSum < target) {
          // update the result if currentSum is closer to target
          if (abs(result - target) > abs(currentSum - target)) {
            result = currentSum;
          }
          // Move the first pointer to the right to increase the sum.
          ++ptr1;
        } else {
          // update the result if currentSum is closer to target
          if (abs(result - target) > abs(currentSum - target)) {
            result = currentSum;
          }
          // Move the second pointer to the left to decrese the sum.
          --ptr2;
        }
      }
    }
    return result;
  }
};
// @lc code=end
