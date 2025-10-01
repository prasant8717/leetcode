class Solution {
private:
    bool teach(vector<unordered_set<int>>& us, int i, int j) {
        for (int k : us[i])
            if (us[j].contains(k))
                return false;
        return true;
    }

public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
        unordered_set<int> us;
        unordered_map<int, int> um;
        vector<unordered_set<int>> vus;
        for (vector<int>& v : languages)
            vus.push_back({v.begin(), v.end()});
        for (vector<int>& v : friendships) {
            int i = v[0] - 1;
            int j = v[1] - 1;
            if (teach(vus, i, j)) {
                us.insert(i);
                us.insert(j);
            }
        }
        for (int u : us)
            for (int t : vus[u])
                ++ um[t];
        int m = 0;
        for (auto& [_, k] : um)
            if (m < k)
                m = k;
        return us.size() - m;
    }
};
