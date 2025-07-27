class Solution:
    def check(self, i: int, j: int, ls: int, lp: int, s: str, p: str) -> bool:
        if j >= lp:
            return i == ls
        if (j + 1 < lp) and (p[j + 1] == '*'):
            sts = self.check(i, j + 2, ls, lp, s, p)
            sts = sts or ((i < ls) and ((s[i] == p[j]) or (p[j] == '.')) and self.check(i + 1, j, ls, lp, s, p))
            return sts
        return (i < ls) and ((s[i] == p[j]) or (p[j] == '.')) and self.check(i + 1, j + 1, ls, lp, s, p)

    def isMatch(self, s: str, p: str) -> bool:
        return self.check(0, 0, len(s), len(p), s, p)
