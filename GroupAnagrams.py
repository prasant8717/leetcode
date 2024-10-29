class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        col = collections.defaultdict(list)
        for s in strs:
            key = ''.join(sorted(s))
            col[key].append(s)
        return col.values()       
