class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.dp = []
        self.dp.append(nums[0])
        for i in range(1, len(nums)):
            self.dp.append(nums[i] + self.dp[-1])
            
        

    def sumRange(self, left: int, right: int) -> int:
        return self.dp[right] - self.dp[left] + self.nums[left]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)