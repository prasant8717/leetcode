class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums1.size(); ++ i)
            ++ um[nums1[i]];
        vector<int> out;
        for (int i = 0; i < nums2.size(); ++ i)
            if (um[nums2[i]] -- > 0)
                out.push_back(nums2[i]);
        return out;        
    }
};
