class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        str_len = [len(s) for s in strs]
        min_l = min(str_len)
        prefix = ""
        for i in range(min_l):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if strs[j][i] != c:
                    return prefix
            prefix = prefix + c
        return prefix