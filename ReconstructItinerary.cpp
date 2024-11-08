class Solution {
public:
    void construct(unordered_map<string, vector<string>>& m, string s, vector<string>& o) {
        while(m[s].empty() == 0) {
            string t = m[s].back();
            m[s].pop_back();
            construct(m, t, o);
        }
        o.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend());
        int l = tickets.size();
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < l; ++ i) {
            map[tickets[i][0]].push_back(tickets[i][1]);
        }
        vector<string> out;
        string s = "JFK";
        construct(map, s, out);
        reverse(out.begin(), out.end());
        return out;
    }
};
