class Solution(object):
    def findWinners(self, matches):
        lose = [0] * 100005;
        s = set()
        for x in matches:
            lose[x[1]]+=1
            s.add(x[0]); s.add(x[1]);
        ans = list(s)
        ans.sort()
        res = []
        win1 = []; lose1 = []
        for x in ans: 
            if lose[x] == 0: win1.append(x)
            if lose[x] == 1: lose1.append(x);
        res.append(win1); res.append(lose1);
        return res
solution = Solution()
print(solution.findWinners([[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]))