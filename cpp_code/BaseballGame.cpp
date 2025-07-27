class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for (int i = 0; i < operations.size(); ++ i) {
            if (operations[i] == "C") {
                v.pop_back();
            } else if (operations[i] == "D") {
                v.push_back(v[v.size() - 1] << 1);
            } else if (operations[i] == "+") {
                int n = v.size();
                int t = v[n - 1] + v[n - 2];
                v.push_back(t);
            } else {
                v.push_back(stoi(operations[i]));
            }
        }
        int res = 0;
        for (int i = 0; i < v.size(); ++ i)
            res += v[i];
        return res;
    }
};
