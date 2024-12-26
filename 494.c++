class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int value) {
        if (i == nums.size()) {
            if (value == target) {
                return 1;
            } else
                return 0;
        }
        return solve(nums, target, i + 1, value + (nums[i] * -1)) +
               solve(nums, target, i + 1, value + nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, target, 0, 0);
    }
};