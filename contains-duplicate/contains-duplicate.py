class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        x = set()
        for e in nums:
            x.add(e)
        
        return len(nums) != len(x)
    
        