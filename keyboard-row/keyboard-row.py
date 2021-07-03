class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        m = {x: 1 for x in "qwertyuiop"}
        m.update({x: 2 for x in "asdfghjkl"})
        m.update({x: 3 for x in "zxcvbnm"})
        
        
        ans = []
        for w in words:
            w_l = w.lower()
            base = m[w_l[0]]
            f = True
            for c in w_l:
                if m[c]!= base:
                    f = False
                    break
            if f:
                ans.append(w)
        return ans
                