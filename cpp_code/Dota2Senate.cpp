class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq;
        queue<int> dq;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                rq.push(i);
            } else {
                dq.push(i);
            }
        }
        while (!rq.empty() && !dq.empty()) {
            int ridx = rq.front();
            int didx = dq.front();
            rq.pop();
            dq.pop();
            if (ridx < didx) {
                rq.push(ridx + n);
            } else {
                dq.push(didx + n);
            }
        }
        return rq.empty() ? "Dire" : "Radiant";        
    }
};
