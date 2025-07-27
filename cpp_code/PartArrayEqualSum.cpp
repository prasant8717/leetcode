class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); ++ i)
            sum += arr[i];
        if (sum % 3 != 0)
            return false;
        int k = sum / 3;
        int t = 0;
        int p = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            t += arr[i];
            if (t == k) {
                t = 0;
                p ++;
            }
        }
        return (p >= 3);
    }
};
