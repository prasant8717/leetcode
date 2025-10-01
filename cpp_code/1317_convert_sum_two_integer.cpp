class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 0;
        int b = 0;
        for (int i = 1; i <= (n >> 1); ++ i) {
            a = i;
            b = n - i;
            if ((to_string(a).find('0') == string::npos) &&
                (to_string(b).find('0') == string::npos))
                return {a, b};
        }
        return {0, 0};
    }
};
