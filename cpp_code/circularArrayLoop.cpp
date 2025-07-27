class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++ i) {
            if (nums[i] == 0)
                continue;
            int s = i;
            int tf = (i + (nums[i] % n) + n) % n;
            int f = tf;
            while (((nums[s] * nums[f]) > 0) &&
                   ((nums[s] * nums[(f + (nums[f] % n) + n) % n]) > 0)) {
                if (s == f) {
                    int ts = (s + (nums[s] % n) + n) % n;
                    if (s != ts)
                        return true;
                    break;
                }
                s = (s + (nums[s] % n) + n) % n;
                int tff = (f + (nums[f] % n) + n) % n;
                f = (tff + (nums[tff] % n) + n) % n;
            }
            int j = i;
            int tj = (j + (nums[j] % n) + n) % n;
            while (nums[j] * nums[tj] > 0) {
                nums[j] = 0;
                j = (j + (nums[j] % n) + n) % n;
                tj = (j + (nums[j] % n) + n) % n;
            }
        }
        return false;
    }
};
