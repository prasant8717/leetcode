class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> v(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; ++ i) {
            for (int j = 1; j <= n2; ++ j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    v[i][j] = v[i - 1][j - 1] + 1;
                } else {
                    v[i][j] = v[i - 1][j];
                    if (v[i][j] < v[i][j - 1])
                        v[i][j] = v[i][j - 1];
                }
            }
        }
        return v[n1][n2];        
    }
};
