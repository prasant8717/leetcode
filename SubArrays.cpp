class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int res = 0;
        int s = 0;
        int m = 1e9 + 7;
        int c0 = 1;
        int c1 = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            s += arr[i];
            if (s % 2) {
                res = (res + c0) % m;
                c1 ++;
            } else {
                res = (res + c1) % m;
                c0 ++;
            }
        }
        return res;
    }
};
