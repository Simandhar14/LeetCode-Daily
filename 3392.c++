class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 2; i < n; i++) {
            double first = nums[i - 2];
            double val = nums[i - 1] / 2.0;
            double third = nums[i];
            if ((first + third) == val)
                result++;
        }
        return result;
    }
};
