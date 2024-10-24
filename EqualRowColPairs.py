class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        tran = [list(col) for col in zip(*grid)]
        cnt = 0
        for row in grid:
            for trow in tran:
                if row == trow:
                    cnt += 1
        return cnt
