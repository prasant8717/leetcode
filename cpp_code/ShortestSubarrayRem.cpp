class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0;
        for (int i = 0; i < arr.size() - 1; ++ i) {
            if (arr[i + 1] >= arr[i]) {
                l ++;
                continue;
            }
            break;
        }
        int r = arr.size() - 1;
        for (int i = arr.size() - 1; i > 0; -- i) {
            if (arr[i - 1] <= arr[i]) {
                r --;
                continue;
            }
            break;
        }
        int res = arr.size() - l - 1;
        if (res > r)
            res = r;
        int ll = l;
        int rr = arr.size() - 1;
        while ((ll >= 0) && (rr >= r) && (rr > ll)) {
            if (arr[ll] <= arr[rr])
                -- rr;
            else
                -- ll;
            if (res > (rr - ll))
                res = rr - ll;
        }
        return res;
    }
};
