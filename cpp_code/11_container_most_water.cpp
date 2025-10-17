class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int sz = height.size();
        int l = 0;
        int r = sz - 1;
        while(l < r) {
            int t = height[l];
            if (height[l] > height[r]) {
                t = height[r];
            }
            int ta = t * (r - l);
            if (res < ta) {
                res = ta;
            }
            if (height[l] < height[r]) {
                l ++;
            } else {
                r --;
            }
        }
        return res;
    }
};
