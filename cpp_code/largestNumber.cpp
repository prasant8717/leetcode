class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int i = 0; i < nums.size(); ++ i)
            v.push_back(to_string(nums[i]));
        sort(v.begin(), v.end(), [](string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        if (v[0] == "0")
            return "0";
        string out;
        for (int i = 0; i < v.size(); ++ i) 
            out += v[i];
        return out;
    }
};
