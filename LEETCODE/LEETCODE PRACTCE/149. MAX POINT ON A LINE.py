class Solution(object):
    def maxPoints(self, points):
        if len(points) <= 1:
            return len(points)       
        max_points = 1
        slope_counts = dict()
        hsg = set()
        for i in range(len(points) - 1):
            for j in range(i + 1, len(points)):
                point1 = tuple(points[i]); point2 = tuple(points[j])
                x1, y1 = point1; x2, y2 = point2
                if x1 == x2: slope = float('inf')
                else: slope = (y2 - y1) / (x2 - x1)
                hsg.add(slope)
                if slope in slope_counts:
                    slope_counts[slope].add(point1)
                    slope_counts[slope].add(point2)
                else:
                    slope_counts[slope] = {point1, point2}  
                print(slope)    
            print("_")
            # In điểm cho từng hệ số góc
        for slope in hsg:
            print(f"h: {slope}")
            print(f"d: {len(slope_counts[slope])}")
            print("-----")

# Example usage:
solution = Solution()
points = [[0,0],[4,5],[7,8],[8,9],[5,6],[3,4],[1,1]]
result = solution.maxPoints(points)
print(result)

            