#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
# https://leetcode.com/problems/3sum/description/
#
# algorithms
# Medium (34.75%)
# Likes:    30677
# Dislikes: 2850
# Total Accepted:    3.6M
# Total Submissions: 10.5M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# Given an integer array nums, return all the triplets [nums[i], nums[j],
# nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
# nums[k] == 0.
# 
# Notice that the solution set must not contain duplicate triplets.
# 
# 
# Example 1:
# 
# 
# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Explanation: 
# nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
# nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
# nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
# The distinct triplets are [-1,0,1] and [-1,-1,2].
# Notice that the order of the output and the order of the triplets does not
# matter.
# 
# 
# Example 2:
# 
# 
# Input: nums = [0,1,1]
# Output: []
# Explanation: The only possible triplet does not sum up to 0.
# 
# 
# Example 3:
# 
# 
# Input: nums = [0,0,0]
# Output: [[0,0,0]]
# Explanation: The only possible triplet sums up to 0.
# 
# 
# 
# Constraints:
# 
# 
# 3 <= nums.length <= 3000
# -10^5 <= nums[i] <= 10^5
# 
# 
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        for i in range(n-2):
            # note the while vs if, we need to avoid the endless loop
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            r = n - 1
            while l < r:
                temp = nums[l] + nums[r] + nums[i]
                if (temp < 0):
                    l += 1
                elif (temp > 0):
                    r -= 1
                else:
                    res.append([nums[i], nums[l], nums[r]])
                    l += 1 
                    r -= 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                    while l < r and nums[r] == nums[r+1]:
                        r -= 1
        # pay attention to the location of the return result, because python don't have {}
        return res    
        
# @lc code=end

