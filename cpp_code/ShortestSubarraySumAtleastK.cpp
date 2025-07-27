class Solution {
public:
    inline int shortest(vector<int>& nums, int s, int l, int k) {
        int sum = 0;
        int res = 0;
        int min = INT_MAX;
        for (int i = s; i < l; ++ i) {
            if (sum + nums[i] >= k) {
                res ++;
                if (res < min)
                    min = res;
                sum = nums[i];
                res = 0;
                break;
            } else {
                sum += nums[i];
                res ++;
            }
        }
        return min == INT_MAX ? -1 : min;
    }
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = shortest(nums, i, nums.size(), k);
            if (t != -1) {
                if (res > t)
                    res = t;
            }
        }
        if (res == INT_MAX)
            res = -1;
        return res;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long> v(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++ i)
            v[i + 1] = v[i] + nums[i];
        deque<int> d;
        int res = nums.size() + 1;
        for (int i = 0; i <= nums.size(); ++ i) {
            while ((d.empty() == 0) && (v[i] - v[d.front()] >= k)) {
                if (res > i - d.front())
                    res = i - d.front();
                d.pop_front();
            }
            while ((d.empty() == 0) && (v[d.back()] >= v[i]))
                d.pop_back();
            d.push_back(i);
        }
        if (res > nums.size())
            res = -1;
        return res;
    }
};
