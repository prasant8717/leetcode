class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> out;
        int carry = 0;
        for (int i = num.size() - 1; i >= 0 || k || carry; -- i) {
            int t = 0;
            if (i >= 0)
                t = num[i];
            carry += t + (k % 10);
            out.push_back(carry % 10);
            carry /= 10;
            k /= 10;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
