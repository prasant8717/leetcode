class Solution {
public:
    bool rotateString(string s, string goal) {
        int l = s.length();
        int g = goal.length();
        if (l != g)
            return false;
        int i = 0;
        vector<int> vc;
        for (int i = 0; i < l; ++ i) {
            if (s[i] == goal[0])
                vc.push_back(i);
        }
        for (int k = 0; k < vc.size(); ++ k) {
            bool sts =  true;
            for (int j = 0; j < l; ++ j) {
                if (s[(vc[k] + j) % l] != goal[j]) {
                    sts = false;
                    break;
                }
            }
            if (sts == true)
                return true;
        }
        return false;
    }
};
