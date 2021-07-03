class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_day = inf
        res = 0
        for i in range(len(prices)):
            
            res = max(res, prices[i] - min_day)
            min_day = min(min_day, prices[i])
        return res
            
            
        