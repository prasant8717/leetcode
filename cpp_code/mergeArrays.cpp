class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> vid(1001);
        for (int i = 0; i < nums1.size(); ++ i) {
            vid[nums1[i][0]] += nums1[i][1];
        }
        for (int i = 0; i < nums2.size(); ++ i) {
            vid[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>> out;
        for (int i = 0; i < 1001; ++ i) {
            if (vid[i] != 0) {
                out.push_back({i, vimd[i]});
            }
        }
        return out;
    }
};
