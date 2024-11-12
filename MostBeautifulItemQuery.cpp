class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ranges::sort(items);
        for (int i = 0; i < items.size() - 1; ++i) {
            if (items[i + 1][1] < items[i][1])
            items[i + 1][1] = items[i][1];
        }
        vector<int> out;
        for (int i = 0; i < queries.size(); ++ i) {
            int k = upper_bound(cbegin(items), cend(items), vector<int>({queries[i] + 1, 0})) - cbegin(items);
            out.emplace_back(k ? items[k - 1][1] : 0);
        }
        return out;
    }
};
