class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> v;
        int k = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            int t = v.size();
            v.push_back(arr[i]);
            for (int j = k; j < t; ++ j)
                if (v.back() != (v[j] | arr[i]))
                    v.push_back(v[j] | arr[i]);
                k = t;
        }
        return unordered_set<int>(v.begin(), v.end()).size();
    }
};
