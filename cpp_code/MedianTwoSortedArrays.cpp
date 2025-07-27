class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int, vector<int>> que;
        for (int i = 0; i < nums1.size(); ++ i) {
            que.push(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++ i) {
            que.push(nums2[i]);
        }
        int tmp = nums1.size() + nums2.size();
        for (int i = 0; i < tmp / 2 - 1; ++ i) {
            que.pop();
        }
        if (tmp % 2 == 0) {
            long long sum = que.top();
            que.pop();
            sum += que.top();
            return (double)sum / 2;
        } else {
            que.pop();
            return que.top();
        }
    }
};
