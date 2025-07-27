struct rt {
    long long et;
    int rd;
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> vc(n);
        ranges::sort(meetings);
        auto fn = [](rt& a, rt& b) {
            return a.et == b.et ? a.rd > b.rd : a.et > b.et;
        };
        priority_queue<rt, vector<rt>, decltype(fn)> pqrt(fn);
        priority_queue<int, vector<int>, greater<>> pqi;
        for (int i = 0; i < n; ++ i)
            pqi.push(i);
        for (int i = 0; i < meetings.size(); ++ i) {
            int s = meetings[i][0];
            int e = meetings[i][1];
            while ((pqrt.empty() == 0) && (pqrt.top().et <= s))
                pqi.push(pqrt.top().rd), pqrt.pop();
            if (pqi.empty()) {
                auto [et, rd] = pqrt.top();
                pqrt.pop();
                ++ vc[rd];
                pqrt.push({et + (e - s), rd});
            } else {
                int rd = pqi.top();
                pqi.pop();
                ++ vc[rd];
                pqrt.push({e, rd});
            }
        }
        return ranges::max_element(vc) - vc.begin();
    }
};
