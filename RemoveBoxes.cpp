class Solution {
public:
    int remove(vector<int>& boxes, int i, int j, int k,
               vector<vector<vector<int>>>& v) {
        if (i > j)
            return 0;
        if (v[i][j][k] > 0)
            return v[i][j][k];
        int r = j;
        int b = k + 1;
        while ((r > 0) && (boxes[r - 1] == boxes[r])) {
            -- r;
            ++ b;
        }
        v[i][j][k] = remove(boxes, i, r - 1, 0, v) + b * b;
        for (int t = i; t < r; ++ t)
            if (boxes[t] == boxes[r]) {
                int tmp = remove(boxes, i, t, b, v) +
                          remove(boxes, t + 1, r - 1, 0, v);
                if (tmp > v[i][j][k])
                    v[i][j][k] = tmp;
            }
        return v[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> vb(n, vector<vector<int>>(n, vector<int>(n)));
        return remove(boxes, 0, n - 1, 0, vb);        
    }
};
