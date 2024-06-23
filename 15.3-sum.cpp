/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (34.75%)
 * Likes:    30677
 * Dislikes: 2850
 * Total Accepted:    3.6M
 * Total Submissions: 10.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // this is a set to deduplicate the result.
    set<vector<int>> dedupSet;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      int target = -nums[i];
      // define two pointers, ptr1 is from i+1, and ptr2 is from the end of the
      // nums array.
      int ptr1 = i + 1, ptr2 = nums.size() - 1;

      while (ptr1 < ptr2) {
        if (nums[ptr1] + nums[ptr2] == target) {
          dedupSet.insert(vector<int>{nums[i], nums[ptr1], nums[ptr2]});
          ++ptr1, --ptr2;
        } else if (nums[ptr1] + nums[ptr2] < target) {
          ++ptr1;
        } else {
          --ptr2;
        }
      }
    }
    auto result = vector<vector<int>>(dedupSet.begin(), dedupSet.end());
    return result;
  }
};
// @lc code=end
