class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        r = collections.Counter(ransomNote)
        m = collections.Counter(magazine)
        return all(r[ch] <= m[ch] for ch in string.ascii_lowercase)
