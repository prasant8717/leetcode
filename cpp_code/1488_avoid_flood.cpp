class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> um;
        set<int> si;
        int sz = rains.size();
        vector<int> out(sz, -1);
        for (int i = 0; i < sz; ++ i) {
            int t = rains[i];
            if (t == 0) {
                si.insert(i);
                continue;
            }
            if (auto u = um.find(t); u != um.cend()) {
                auto i = si.upper_bound(u->second);
                if (i == si.cend())
                    return {};
                out[*i] = t;
                si.erase(i);
            }
            um[t] = i;
        }
        for (int i : si)
            out[i] = 1;
        return out;
    }
};
