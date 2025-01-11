class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> vl(n);
        vector<int> vr(n);
        int cnt = 0;
        for (int i = 1; i < n; ++ i) {
            if (boxes[i - 1] == '1')
                ++ cnt;
            vl[i] = vl[i - 1] + cnt;
        }
        cnt = 0;
        for (int i = n - 2; i >= 0; -- i) {
            if (boxes[i + 1] == '1')
                ++ cnt;
            vr[i] = vr[i + 1] + cnt;
        }
        vector<int> out(n);
        for (int i = 0; i < n; ++ i)
            out[i] = vl[i] + vr[i];
        return out;        
    }
};
