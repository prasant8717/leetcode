class Solution {
private:
    void update(unordered_map<int, int>& um,
                multiset<pair<int, int>>& msp1,
                multiset<pair<int, int>>& msp2,
                long long& sum, int num, int cnt) {
        if (um[num] > 0) {
            if (auto it = msp2.find({um[num], num});
                it != msp2.end()) {
                msp2.erase(it);
            } else {
                it = msp1.find({um[num], num});
                msp1.erase(it);
                sum -= num * um[num];
            }
        }
        um[num] += cnt;
        if (um[num] > 0)
            msp2.insert({um[num], num});
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> um;
        multiset<pair<int, int>> msp1;
        multiset<pair<int, int>> msp2;
        vector<int> out;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            update(um, msp1, msp2, sum, nums[i], 1);
            if (i >= k)
                update(um, msp1, msp2, sum, nums[i - k], -1);
            while (!msp2.empty() && (msp1.size() < x)) {
                auto [cnt, b] = *msp2.rbegin();
                msp2.erase(-- msp2.end());
                msp1.insert({cnt, b});
                sum += b * cnt;
            }
            while (!msp2.empty() && (*msp2.rbegin() > *msp1.begin())) {
                auto [cnt1, t] = *msp1.begin();
                auto [cnt2, b] = *msp2.rbegin();
                msp2.erase(-- msp2.end());
                msp1.erase(msp1.begin());
                msp2.insert({cnt1, t});
                msp1.insert({cnt2, b});
                sum += b * cnt2;
                sum -= t * cnt1;
            }
            if (i >= k - 1)
                out.push_back(sum);
        }
        return out;
    }
};
