class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&score](int x, int y) {
            return score[x] > score[y];
        });
        vector<string> out(n);
        for (int i = 0; i < n; ++ i) {
            if (i == 0)
                out[idx[i]] = "Gold Medal";
            else if (i == 1)
                out[idx[i]] = "Silver Medal";
            else if (i == 2)
                out[idx[i]] = "Bronze Medal";
            else
                out[idx[i]] = to_string(i + 1);
        }
        return out;
    }
};
