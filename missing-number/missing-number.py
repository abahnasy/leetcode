class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total = 0
        for n in range(1, len(nums)+1):
            total = total + n
        for n in nums:
            
            total = total - n
                
        return total