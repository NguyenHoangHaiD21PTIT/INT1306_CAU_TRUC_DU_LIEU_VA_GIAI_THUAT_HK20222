class Solution(object):
    def letterCombinations(self, digits):
        if not digits: return []
        d = dict()
        d['2'] = 'abc'; d['3'] = 'def'; d['4'] = 'ghi'
        d['5'] = 'jkl'; d['6'] = 'mno'; d['7'] = 'pqrs'
        d['8'] = 'tuv'; d['9'] = 'wxyz'
        result = ['']
        for digit in digits:
            temp_result = []
            for combination in result:
                for char in d[digit]: temp_result.append(combination + char)
            result = temp_result
        return result

solution = Solution()
print(solution.letterCombinations("234"))  