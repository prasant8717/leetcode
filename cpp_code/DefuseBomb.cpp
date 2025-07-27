class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> out;
        for (int i = 0; i < code.size(); ++ i) {
            if (k > 0) {
                int sum = 0;
                for (int j = 0; j < k; ++ j)
                    sum += code[(i + j + 1) % code.size()];
                out.push_back(sum);
                sum = 0;    
            } else if (k < 0) {
                int sum = 0;
                for (int j = k; j < 0; ++ j)
                    sum += code[(code.size() + i + j) % code.size()];
                out.push_back(sum);
                sum = 0;
            } else {
                out.push_back(0);
            }
        }
        return out;
    }
};
