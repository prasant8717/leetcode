class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const unordered_set<int> s1{nums1.begin(), nums1.end()};
        const unordered_set<int> s2{nums2.begin(), nums2.end()};
        vector<vector<int>> out(2);
        for (const int num : s1)
            if (!s2.contains(num))
                out[0].push_back(num);
        for (const int num : s2)
            if (!s1.contains(num))
                out[1].push_back(num);
        return out;
    }
};
