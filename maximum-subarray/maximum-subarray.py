class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_ = nums[0]
        last = nums[0]
        for i in range(1, len(nums)):
            last = max(last + nums[i], nums[i])
            max_ = max(last, max_)
            
        return max_
        