class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int i = 0;
        int j = 0;
        for (; i < m && j < n;) {
            if (nums1[i] < nums2[j]) {
                v.push_back(nums1[i]);
                ++i;
            } else {
                v.push_back(nums2[j]);
                ++j;
            }
        }
        for (int k = i; k < m; ++ k) {
            v.push_back(nums1[k]);
        }
        for (int k = j; k < n; ++ k) {
            v.push_back(nums2[k]);
        }
        for (int k = 0; k < m + n; ++ k) {
            nums1[k] = v[k];
        }
    }
};
