class Solution {
private:
    int count(vector<int>& vh) {
        stack<int> stk;
        vector<int> vs(vh.size());
        for (int i = 0; i < vh.size(); ++ i) {
            while ((stk.empty() == 0) && (vh[stk.top()] >= vh[i]))
                stk.pop();
            if (stk.empty() == 0) {
                int p = stk.top();
                vs[i] = vs[p] + vh[i] * (i - p);
            } else {
                vs[i] = vh[i] * (i + 1);
            }
            stk.push(i);
        }
        return accumulate(vs.begin(), vs.end(), 0);
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        vector<int> vh(mat[0].size());
        for (int k = 0; k < mat.size(); ++ k) {
            for (int i = 0; i < mat[k].size(); ++ i)
                vh[i] = mat[k][i] == 0 ? 0 : vh[i] + 1;
            res += count(vh);
        }
        return res;
    }
};
