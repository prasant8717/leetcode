class Solution {
public:
    void sort(vector<int>& v, int l, int r) {
        if (l >= r)
            return;
        int i = l - 1;
        int j = r + 1;
        int t = v[(l + r) >> 1];
        while (i < j) {
            while (v[++ i] < t);
            while (v[-- j] > t);
            if (i < j) {
                int x = v[i];
                v[i] = v[j];
                v[j] = x;
            }
        }
        sort(v, l, j);
        sort(v, j + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
