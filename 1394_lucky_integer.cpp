class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> v(501);
        for (int i = 0; i < arr.size(); ++ i) {
            ++ v[arr[i]];
        }
        int res = -1;
        for (int i = 0; i < 501; ++ i) {
            if (v[i])
                if (v[i] == i) {
                    if (res < i)
                        res = i;
                }
        }
        return res;
    }
};
