class Solution {
public:
    bool check(vector<vector<int>>& v, 
               vector<int>& in, int i, int j,
               unordered_map<int, int>& um) {
        int n = v.size();
        if (i == n - 1) {
            return true;
        }
        if (v[i][j] != -1) {
            return v[i][j];
        }
        for (int k = j - 1; k <= j + 1; ++ k) {
            if ((k > 0) && um.count(in[i] + k) &&
                check(v, in, um[in[i] + k], k, um)) {
                return v[i][j] = true;
            }
        }
        return v[i][j] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> v(n, vector<int>(n, -1));
        unordered_map<int, int> um;
        for (int i = 0; i < n; ++ i) {
            um[stones[i]] = i;
        }
        return check(v, stones, 0, 0, um);        
    }
};
