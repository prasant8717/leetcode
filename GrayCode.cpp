class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> out;
        for (int i = 0; i < (1 << n);  ++ i) {
            out.push_back(i ^  (i >> 1));
        }
        return out;
    }
};
