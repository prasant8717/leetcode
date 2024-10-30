class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> que{{{startGene, 0}}};
        unordered_set<string> set = {startGene};
        while (que.empty() == 0) {
            auto [g, d] = que.front();
            que.pop();
            if (g == endGene) {
                return d;
            }
            for (int i = 0; i < bank.size(); ++ i) {
                int c = 2;
                for (int j = 0; j < bank[0].size() && c; ++ j) {
                    c -= g[j] != bank[i][j];
                }
                if ((c != 0) && (set.contains(bank[i]) == 0)) {
                    set.insert(bank[i]);
                    que.push({bank[i], d + 1});
                }
            }
        }
        return -1;        
    }
};
