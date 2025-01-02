class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        using pii = pair<int, int>;
        stack<pii> stk;
        stk.emplace(0, 0);
        auto hf = [](const pii& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<pii, decltype(hf)> vis(0, hf);
        while (stk.size()) {
            auto st = stk.top();
            stk.pop();
            if (vis.count(st))
                continue;
            vis.emplace(st);
            auto [i, j] = st;
            if ((i == target) || (j == target) ||
                (i + j == target))
                return true;
            stk.emplace(x, j);
            stk.emplace(i, y);
            stk.emplace(0, j);
            stk.emplace(i, 0);
            int a = i;
            if (a > y - j)
                a = y - j;
            int b = j;
            if (b > x - i)
                b = x - i;
            stk.emplace(i - a, j + a);
            stk.emplace(i + b, j - b);
        }
        return false;
    }
};
