class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        unordered_set<int> us;
        for (int i = 0; i < nums1.size(); ++ i)
            us.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); ++ i)
            if (us.erase(nums2[i]))
                out.push_back(nums2[i]);
        return out;        
    }
};
