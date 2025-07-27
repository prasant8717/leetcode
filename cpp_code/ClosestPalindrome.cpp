class Solution {
public:
    unordered_set<long> get(string& n) {
        int t = n.size();
        unordered_set<long> us;
        us.insert((long) pow(10, t - 1) - 1);
        us.insert((long) pow(10, t) + 1);
        long l = stol(n.substr(0, (t + 1) / 2));
        for (long i = l - 1; i <= l + 1; ++ i) {
            string px = to_string(i);
            string tx = px + string(px.rbegin() + (t & 1), px.rend());
            us.insert(stol(tx));
        }
        us.erase(stol(n));
        return us;
    }
    string nearestPalindromic(string n) {
        long t = stol(n);
        long res = -1;
        for (long i : get(n))
            if ((res == -1) || (abs(i - t) < abs(res - t)) ||
                (abs(i - t) == abs(res - t)) && (i < res))
                res = i;
        return to_string(res);        
    }
};
