class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> ums;
        unordered_map<string, vector<string>> umv;
        for (int i = 0; i < recipes.size(); ++ i) {
            for (int j = 0; j < ingredients[i].size(); ++ j)
                umv[ingredients[i][j]].push_back(recipes[i]);
            ums[recipes[i]] = ingredients[i].size();
        }
        queue<string> q;
        for (int i = 0; i < supplies.size(); ++ i)
            q.push(supplies[i]);
        vector<string> out;
        while (q.empty() == 0) {
            for (int sz = q.size(); sz != 0; -- sz) {
                auto qt = q.front();
                q.pop();
                for (auto& v : umv[qt]) {
                    if (-- ums[v] == 0) {
                        out.push_back(v);
                        q.push(v);
                    }
                }
            }
        }
        return out;
    }
};
