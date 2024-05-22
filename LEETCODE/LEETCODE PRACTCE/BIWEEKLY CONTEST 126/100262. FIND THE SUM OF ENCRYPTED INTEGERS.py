def Max(x):
    res = -1
    cnt=0
    while x:
        res = max(res, x%10)
        cnt+=1
        x//=10
    ans = 0
    for i in range(cnt): ans = ans * 10 + res
    return ans


class Solution(object):
    def sumOfEncryptedInt(self, nums):
        tong = 0
        for x in nums: tong+=Max(x)    
        return tong 
    
sol = Solution()
print(sol.sumOfEncryptedInt([1, 2, 3]))
print(sol.sumOfEncryptedInt([10,21,31]))
