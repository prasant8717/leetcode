class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++ i) {
            while ((dq.empty() == 0) && (dq.back() < nums[i]))
                dq.pop_back();
            dq.push_back(nums[i]);
            if ((i >= k) && (nums[i - k] == dq.front()))
                dq.pop_front();
            if (i >= k - 1)
                v.push_back(dq.front());
        }
        return v;
    }
};
