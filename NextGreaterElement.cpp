class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        for (int i = 0; i < nums1.size(); ++ i) {
            int idx = 0;
            for (int j = 0; j < nums2.size(); ++ j) {
                if (nums1[i] != nums2[j])
                    continue;
                idx = j;
            }
            int max = -1;
            for (int j = idx + 1; j < nums2.size(); ++ j)
                if (nums1[i] < nums2[j]) {
                    max = nums2[j];
                    break;
                }
            out.push_back(max);
        }
        return out;
    }
};
