class Solution {
public:
    bool canChange(string start, string target) {
        int s = 0;
        int t = 0; 
        int n = start.length();
        while ((s <= n) && (t <= n)) {
            while ((s < n) && (start[s] == '_'))
                ++ s;
            while ((t < n) && (target[t] == '_'))
                ++ t;
            if ((s == n) || (t == n))
                return (s == n) && (t == n);
            if (start[s] != target[t])
                return false;
            if ((start[s] == 'R') && (s > t))
                return false;
            if ((start[s] == 'L') && (s < t))
                return false;
            ++ s;
            ++ t;
        }
        return true;        
    }
};
