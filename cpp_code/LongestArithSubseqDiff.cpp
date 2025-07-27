class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            int t = arr[i];
            if (auto it = map.find(t - difference); it != map.cend())
                map[t] = it->second + 1;
            else
                map[t] = 1;
            if (res < map[t])
                res = map[t];
        }
        return res;
    }
};
