class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> high;
        vector<int> eq;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] < pivot)
                less.push_back(nums[i]);
            else if (nums[i] > pivot)
                high.push_back(nums[i]);
            else
                eq.push_back(pivot);
        }
        vector<int> out = less;
        out.insert(out.end(), eq.begin(), eq.end());
        out.insert(out.end(), high.begin(), high.end());
        return out;
    }
};
