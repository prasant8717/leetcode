class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 1; i < 100; ++ i) {
            int d1 = (i / 10);
            int d2 = (i % 10);
            bool s = false;
            for (int j = 0; j < nums1.size(); ++ j)
                if ((nums1[j] == d1) || (nums1[j] == d2)) {
                    s = true;
                    break;
                }
            if (s == true) {
                for (int j = 0; j < nums2.size(); ++ j)
                    if ((nums2[j] == d1) || (nums2[j] == d2)) 
                        return i;
            }
        }
        return 0;
    }
};
