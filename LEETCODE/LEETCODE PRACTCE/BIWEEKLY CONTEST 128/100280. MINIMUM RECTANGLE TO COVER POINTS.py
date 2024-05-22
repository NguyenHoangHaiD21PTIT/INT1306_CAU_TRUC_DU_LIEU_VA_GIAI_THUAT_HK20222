class Solution(object):
    def minRectanglesToCoverPoints(self, points, w):
        points.sort()  
        rectangles = 0
        curr_right = float('-inf')  #Giới hạn hoành độ tối đa của HCN đang xét
        for x, y in points:
            if x > curr_right:  #Nếu điểm hiện tại vượt quá giới hạn hoành độ tối đa HCN đang xét
                rectangles += 1  #Đẩy điểm này sang 1 HCN mới
                curr_right = x + w  #Cập nhật giới hạn hoành độ tối đa HCN mới
        return rectangles
    
sol = Solution()
print(sol.minRectanglesToCoverPoints([[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]], 1))
print(sol.minRectanglesToCoverPoints([[0,0],[1,1],[2,2],[3,3],[4,4],[5,5],[6,6]], 2))
print(sol.minRectanglesToCoverPoints([[2,3],[1,2]], 0))