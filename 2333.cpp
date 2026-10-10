//cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        vector<int> diff(1e5 + 1, 0);
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            diff[abs(nums1[i] - nums2[i])]++;
        }
        long long ans = 0;
        int k = k1 + k2;
        for (int i = 1e5; i >= 1 && k > 0; i--) {
            if (diff[i] == 0)
                continue;
            int count = min(k, diff[i]);
            diff[i] -= count;
            diff[i - 1] += count;
            k -= count;
        }
        for (int i = 0; i <= 1e5; i++) {
            if (diff[i] == 0)
                continue;
            while (diff[i] > 0) {
                ans += 1LL * i * i;
                diff[i]--;
            }
        }
        return ans;
    }
};
