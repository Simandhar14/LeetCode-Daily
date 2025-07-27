class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hill = 0, valley = 0;
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                left[i] = nums[i - 1];
            } else {
                left[i] = left[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != nums[i + 1]) {
                right[i] = nums[i + 1];
            } else {
                right[i] = right[i + 1];
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if(nums[i]==nums[i-1]) continue;
            if (nums[i] > left[i] && nums[i] > right[i] && left[i] != -1 &&
                right[i] != -1) {
                hill++;
            } else if (nums[i] < left[i] && nums[i] < right[i] &&
                       left[i] != -1 && right[i] != -1) {
                valley++;
            }
        }
        return hill + valley;
    }
};
