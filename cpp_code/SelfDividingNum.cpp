class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;
        for (int i = left; i <= right; ++ i) {
            string s = to_string(i);
            bool b = true;
            for (int k = 0; k < s.size(); ++ k) {
                int t = s[k] - '0';
                if ((t == 0) || (i % t)) {
                    b = false;
                    break;
                }
            }
            if (b == true)
                out.push_back(i);
        }
        return out;
    }
};
