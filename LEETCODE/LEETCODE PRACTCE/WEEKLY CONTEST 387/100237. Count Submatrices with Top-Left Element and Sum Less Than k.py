class Solution(object):
    def countSubmatrices(self, grid, k):
        n, m = len(grid), len(grid[0])
        a = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1): a[i][j] = grid[i - 1][j - 1]
        prefix = [[0] * (m + 1) for _ in range(n + 1)]
        # Xây dựng mảng cộng dồn
        cnt = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j]
                if prefix[i][j] <= k: cnt+=1
        return cnt

sol = Solution()
print(sol.countSubmatrices([[7,2,9],[1,5,0],[2,6,6]], 20))
