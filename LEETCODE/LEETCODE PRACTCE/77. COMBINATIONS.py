from itertools import combinations
class Solution(object):
    def combine(self, n, k):
        a1 = []
        for i in range (1, n + 1): a1.append(i)
        a = combinations(a1, k)
        result = []
        for x in a: result.append(list(x))
        return result

solution = Solution()
print(solution.combine(4, 2))