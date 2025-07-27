class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> vc(501);
        for (int i = 0; i < nums.size(); ++ i)
            vc[nums[i]] ++;
        for (int i = 1; i < 501; ++ i)
            if ((vc[i] & 1) != 0)
                return false;
        return true;
    }
};
