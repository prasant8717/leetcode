class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> uh;
        for (int i = 0; i < arr2.size(); ++ i)
            uh[arr2[i]] = i;
        vector<pair<int, int>> vp;
        for (int i = 0; i < arr1.size(); ++ i) {
            int t = arr2.size();
            if (uh.count(arr1[i]) != 0)
                t = uh[arr1[i]];
            vp.emplace_back(t, arr1[i]);
        }
        ranges::sort(vp);
        for (int i = 0; i < arr1.size(); ++ i)
            arr1[i] = vp[i].second;
        return arr1;
    }
};
