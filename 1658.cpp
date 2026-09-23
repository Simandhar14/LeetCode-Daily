//cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(begin(nums), end(nums), 0);
        if (total == x)
            return n;
        int subarray = total - x, result = INT_MAX;
        int i = 0, sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while (i < j && sum > subarray) {
                sum -= nums[i];
                i++;
            }
            if (sum == subarray) {
                result = min(result, n - (j - i + 1));
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
