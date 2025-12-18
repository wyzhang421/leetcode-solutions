#
# @lc app=leetcode id=977 lang=python3
#
# [977] Squares of a Sorted Array
#
# https://leetcode.com/problems/squares-of-a-sorted-array/description/
#
# algorithms
# Easy (73.41%)
# Likes:    9972
# Dislikes: 265
# Total Accepted:    2.4M
# Total Submissions: 3.3M
# Testcase Example:  '[-4,-1,0,3,10]'
#
# Given an integer array nums sorted in non-decreasing order, return an array
# of the squares of each number sorted in non-decreasing order.
# 
# 
# Example 1:
# 
# 
# Input: nums = [-4,-1,0,3,10]
# Output: [0,1,9,16,100]
# Explanation: After squaring, the array becomes [16,1,0,9,100].
# After sorting, it becomes [0,1,9,16,100].
# 
# 
# Example 2:
# 
# 
# Input: nums = [-7,-3,2,3,11]
# Output: [4,9,9,49,121]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^4
# -10^4 <= nums[i] <= 10^4
# nums is sorted in non-decreasing order.
# 
# 
# 
# Follow up: Squaring each element and sorting the new array is very trivial,
# could you find an O(n) solution using a different approach?
#

# @lc code=start
class Solution:
    # solution 1: time complexity is O(nlogn), space complexity is O(1)
    # def sortedSquares(self, nums: List[int]) -> List[int]:
    #     for i in range(len(nums)):
    #         nums[i] *= nums[i]
    #     nums.sort()
    #     return nums

    # solution 2: two pointers: time complexity is O(n), space complexity is O(1)
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left, right = 0, len(nums)-1
        result = [float('inf')] * len(nums)
        idx = len(nums) - 1
        while idx >= 0:
            if (nums[left] ** 2 > nums[right] ** 2):
                result[idx] = nums[left] ** 2
                left += 1
            else:
                result[idx] = nums[right] ** 2
                right -= 1
            idx -= 1
        return result
        
# @lc code=end

