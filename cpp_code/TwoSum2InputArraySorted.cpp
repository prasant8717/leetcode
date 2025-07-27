class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> out;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                out.push_back(l + 1);
                out.push_back(r + 1);
                break;
            } else if (numbers[l] + numbers[r] < target) {
                l ++;
            } else {
                r --;
            }
        }
        return out;
    }
};
