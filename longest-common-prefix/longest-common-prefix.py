class Solution:
    
    def rec_lcp(self, strs: List[str], l: int, r: int) -> str:
        # base case
        if l == r:
            return strs[l]
        
        mid = l+(r-l)//2
        p1 = self.rec_lcp(strs, l, mid)
        p2 = self.rec_lcp(strs, mid+1, r)
        
        min_ = int(min(len(p1), len(p2)))
        for i in range(min_):
            if p1[i] != p2[i]:
                return p1[0:i]
        
        return p1[0:min_]
        
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        return self.rec_lcp(strs, 0, len(strs)-1)