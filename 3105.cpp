//cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int increasing = 1, decreasing = 1, result = 1;
        for (int i = 1; i < n; i++) {
            increasing = (nums[i] > nums[i - 1]) ? increasing + 1 : 1;
            decreasing = (nums[i] < nums[i - 1]) ? decreasing + 1 : 1;
            result = max({result, increasing, decreasing});
        }
        return result;
    }
};
