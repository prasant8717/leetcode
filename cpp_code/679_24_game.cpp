class Solution {
private:
    const char ops[4] = {'+', '-', '*', '/'};

    bool game(vector<double>& vn) {
        int n = vn.size();
        if (n == 1) {
            return (abs(vn[0] - 24) < 1e-6);
        }
        bool sts = false;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i != j) {
                    vector<double> vt;
                    for (int k = 0; k < n; ++ k) {
                        if ((k != i) && (k != j)) {
                            vt.push_back(vn[k]);
                        }
                    }
                    for (int l = 0; l < sizeof(ops); ++ l) {
                        switch (ops[l]) {
                        case '/':
                            if (vn[j] == 0) {
                                continue;
                            }
                            vt.push_back(vn[i] / vn[j]);
                            break;
                        case '*':
                            vt.push_back(vn[i] * vn[j]);
                            break;
                        case '+':
                            vt.push_back(vn[i] + vn[j]);
                            break;
                        case '-':
                            vt.push_back(vn[i] - vn[j]);
                            break;
                        }
                        sts |= game(vt);
                        if (sts) {
                            return true;
                        }
                        vt.pop_back();
                    }
                }
            }
        }
        return sts;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> vn;
        for (int i = 0; i < cards.size(); ++ i) {
            vn.push_back(static_cast<double>(cards[i]));
        }
        return game(vn);
    }
};
