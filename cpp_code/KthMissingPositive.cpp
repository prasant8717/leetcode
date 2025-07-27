class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<bool> v(arr[n - 1] + 1);
        for (int i = 0; i < n; ++ i) {
            v[arr[i]] = true;
        }
        for (int i = 1; i < v.size(); ++ i) {
            if (v[i] == false) {
                -- k;
            }
            if (k == 0)
                return i;
        }
        return k + arr[n - 1];
    }
};
