class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            if (nums[r] * nums[r] > nums[l] * nums[l]) {
                result.push_back(nums[r]*nums[r]);
                r--;
            } else {
                result.push_back(nums[l]*nums[l]);
                l++;
            }
        }
        reverse(begin(result),end(result));
        return result;
    }
};