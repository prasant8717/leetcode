#if 0
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        for (int i = 0; i < n1; ++ i)
            for (int j = 0; j < n2; ++ j) {
                pq.push((long long)nums1[i] * nums2[j]);
            }
        while (k > 1) {
            pq.pop();
            -- k;
        }
        return pq.top();
    }
};
#endif
class Solution {
private:
    void div_ve(vector<int>& in, vector<int>& v1, vector<int>& v2) {
        for (int t : in)
        if (t < 0)
            v1.push_back(-t);
        else
            v2.push_back(t);
        ranges::reverse(v1);
    }
    long grt_prd(vector<int>& v1, const vector<int>& v2, long long m) {
        long long cnt = 0;
        int j = v2.size() - 1;
        for (long long a : v1) {
            while (j >= 0 && a * v2[j] > m)
                --  j;
            cnt += j + 1;
        }
        return cnt;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> ng1;
        vector<int> ng2;
        vector<int> np1;
        vector<int> np2;
        div_ve(nums1, ng1, ng2);
        div_ve(nums2, np1, np2);
        long long ncnt = ng1.size() * np2.size() + ng2.size() * np1.size();
        int ve = 1;
        if (k > ncnt) {
            k -= ncnt;
        } else {
            k = ncnt - k + 1;
            ve = -1;
            swap(np1, np2);
        }
        long long l = 0;
        long long r = 1e10;
        while (l < r) {
            long long m = (l + r) / 2;
            if (grt_prd(ng1, np1, m) + grt_prd(ng2, np2, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        return ve * l;
    }
};
