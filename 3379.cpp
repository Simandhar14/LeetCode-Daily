//cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
         vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int steps = nums[i];
            if (steps < 0) {
                steps = abs(nums[i]);
                int remaining = steps % n;
                if (remaining <= i)
                    result[i] = nums[i - remaining];
                else {
                    result[i] = nums[n-1-(remaining-i-1)];
                }
            } else {
                int remaining = steps % n;
                if (remaining <= n - 1 - i)
                    result[i] = nums[i + remaining];
                else {
                    result[i] = nums[remaining-(n-1-i)-1];
                }
            }
        }
        return result;
    }
};
