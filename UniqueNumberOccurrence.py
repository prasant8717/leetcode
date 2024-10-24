class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = collections.Counter(arr)
        oc = set()
        for val in cnt.values():
            if val in oc:
                return False
            oc.add(val)
        return True
