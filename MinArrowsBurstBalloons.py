class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        res = 0
        x = -math.inf
        for point in sorted(points, key=lambda y : y[1]):
            if point[0] > x:
                res += 1
                x = point[1]
        return res
