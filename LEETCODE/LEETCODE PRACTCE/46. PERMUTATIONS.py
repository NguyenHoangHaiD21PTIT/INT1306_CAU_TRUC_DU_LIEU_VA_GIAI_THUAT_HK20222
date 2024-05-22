from itertools import permutations
class Solution(object):
    def permute(self, nums):
        #a: list cac hoan vi
        a = permutations(nums)
        result = []
        for x in a: result.append(list(x))
        return result

solution = Solution()
print(solution.permute([1, 2, 3]))