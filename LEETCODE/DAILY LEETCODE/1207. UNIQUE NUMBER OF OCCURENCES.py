class Solution(object):
    def uniqueOccurrences(self, arr):
        d = dict() 
        for x in arr: 
            if x in d: d[x]+=1 
            else: d[x]=1 
        s = set(d.values())
        return len(d) == len(s)
sol = Solution()
print(sol.uniqueOccurrences([1,2,2,1,1,3]))
print(sol.uniqueOccurrences([1,2]))
print(sol.uniqueOccurrences([-3,0,1,-3,1,1,1,-3,10,0]))
print(sol.uniqueOccurrences([26,2,16,16,5,5,26,2,5,20,20,5,2,20,2,2,20,2,16,20,16,17,16,2,16,20,26,16]))