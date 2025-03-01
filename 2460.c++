class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> result;
        int zeros = 0;
        int n = nums.size();
        int i = 0;
        while (i < n ) {
            if (nums[i] == 0) {
                zeros++;
                i++;
                continue;
            }
            if (i < n-1 && nums[i] == nums[i + 1]) {
                result.push_back(nums[i] * 2);
                zeros++;
                i += 2;
            } else {
                result.push_back(nums[i]);
                i++;
            }
        }
        while (zeros--) {
            result.push_back(0);
        }
        return result;
    }
};