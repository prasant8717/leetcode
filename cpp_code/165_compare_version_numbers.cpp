class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        int j = 0;
        for (int i = 0; i < m || j < n; ++ i) {
            int t = 0;
            int u = 0;
            while (i < m && version1[i] != '.') {
                t = t * 10 + (version1[i++] - '0');
            }
            while (j < n && version2[j] != '.') {
                u = u * 10 + (version2[j++] - '0');
            }
            if (t != u) {
                return t < u ? -1 : 1;
            }
            ++ j;
        }
        return 0;
    }
};
