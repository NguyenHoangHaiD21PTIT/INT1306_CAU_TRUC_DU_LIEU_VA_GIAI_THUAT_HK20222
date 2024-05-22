class Solution(object):
    def scoreOfString(self, s):
        score = 0
        for i in range(1, len(s)): score += abs(ord(s[i]) - ord(s[i-1]))
        return score
    
sol = Solution()
print(sol.scoreOfString("hello"))
print(sol.scoreOfString("zaz"))