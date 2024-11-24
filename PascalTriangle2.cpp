class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        vector<int> v(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++ i)
            v[i] = 1;
        for (int i = 1; i <= rowIndex; ++ i) {
            vector<int> t(i + 1);
            for (int j = 1; j < i; ++ j) {
                t[j] = v[j - 1] + v[j];
            }
            for (int j = 1; j < i; ++ j)
                v[j] = t[j];
        }
        return v;
    }
};
