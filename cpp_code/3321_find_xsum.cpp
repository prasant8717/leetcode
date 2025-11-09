class Solution {
private:
    void update(unordered_map<int, int>& um,
                multiset<pair<int, int>>& ms1,
                multiset<pair<int, int>>& ms2,
                long long& sum, int num, int f) {
        if (um[num] > 0) {
            if (auto it = ms2.find({um[num], num}); it != ms2.end()) {
                ms2.erase(it);
            } else {
                it = ms1.find({um[num], num});
                ms1.erase(it);
                sum -= static_cast<long long>(num) * um[num];
            }
        }
        um[num] += f;
        if (um[num] > 0)
            ms2.insert({um[num], num});
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> um;
        multiset<pair<int, int>> msp1;
        multiset<pair<int, int>> msp2;
        vector<long long> out;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            update(um, msp1, msp2, sum, nums[i], 1);
            if (i >= k)
                update(um, msp1, msp2, sum, nums[i - k], -1);
            while (!msp2.empty() && (msp1.size() < x)) {
                auto [cnt, b] = *msp2.rbegin();
                msp2.erase(-- msp2.end());
                msp1.insert({cnt, b});
                sum += static_cast<long long>(b) * cnt;
            }
            while (!msp2.empty() && (*msp2.rbegin() > *msp1.begin())) {
                auto [cnt1, t] = *msp1.begin();
                auto [cnt2, b] = *msp2.rbegin();
                msp2.erase(-- msp2.end());
                msp1.erase(msp1.begin());
                msp2.insert({cnt1, t});
                msp1.insert({cnt2, b});
                sum += static_cast<long long>(b) * cnt2;
                sum -= static_cast<long long>(t) * cnt1;
            }
            if (i >= k - 1)
                out.push_back(sum);
        }
        return out;
    }
};
