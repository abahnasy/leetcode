class Solution:
    def romanToInt(self, s: str) -> int:
        
        d = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        
        if len(s) == 0:
            return 0
        # add the first element
        res = d[s[0]]
        value_last = d[s[0]]
        for c in s[1:]:
            value = d[c]
            res += value
            # not normal case
            if value_last < value:
                res -= value_last*2
            value_last = value
        return res
            
        
        