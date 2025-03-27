class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ranges::sort(arr);
        int d = INT_MAX;
        for (int i = 0; i < arr.size() - 1; ++ i) {
            int t = abs(arr[i + 1] - arr[i]);
            if (d > t)
                d = t;
        }
        vector<vector<int>> out;
        for (int i = 0; i < arr.size() - 1; ++ i) {
            int t = abs(arr[i + 1] - arr[i]);
            if (t == d)
                out.push_back({arr[i], arr[i + 1]});
        }
        return out;
    }
};
