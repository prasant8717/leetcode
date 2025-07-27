class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        res = []
        gr = collections.defaultdict(dict)
        for (p1, p2), val in zip(equations, values):
            gr[p1][p2] = val
            gr[p2][p1] = 1 / val
        def result(p1: str, pm2: str, vis: set[str]) -> float:
            if p1 == pm2:
                return 1.0
            vis.add(p1)
            for p2, val in gr[p1].items():
                if p2 in vis:
                    continue
                out = result(p2, pm2, vis)  # B / C
                if out > 0:  # valid result
                    return val * out  # (A / B) * (B / C) = A / C
            return -1.0  # invalid result
        for p1, pm2 in queries:
            if p1 not in gr or pm2 not in gr:
                res.append(-1.0)
            else:
                res.append(result(p1, pm2, set()))
        return res
