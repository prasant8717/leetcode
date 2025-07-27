class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        vector<int> v(1000);
        for (int i = 0; i < answers.size(); ++ i) {
            int t = answers[i];
            if (v[t] % (t + 1) == 0)
                res += t + 1;
            ++ v[t];
        }
        return res;
    }
};
