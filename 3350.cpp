class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int subarraySize = 1;
        int l1 = -1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                subarraySize++;
            } else {
                ans = max({ans, l1 / 2, subarraySize / 2});
                if (l1 > 0 && subarraySize > 0) {
                    int maxK = min(l1, subarraySize);
                    ans = max(ans, maxK);
                }
                l1 = subarraySize;
                subarraySize = 1;
            }
        }
        ans = max({ans, l1 / 2, subarraySize / 2});
        if (l1 > 0 && subarraySize > 0) {
            int maxK = min(l1, subarraySize);
            ans = max(ans, maxK);
        }
        return ans;
    }
};
