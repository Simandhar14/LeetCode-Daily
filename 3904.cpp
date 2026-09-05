//cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minnum(n);
        int maxnum = nums[0];
        minnum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minnum[i] = min(minnum[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            maxnum = max(maxnum, nums[i]);
            if ((maxnum - minnum[i]) <= k)
                return i;
        }
        return -1;
    }
};
