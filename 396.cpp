//cpp
class Solution {
public:
    int n;
    int calculate(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (i * nums[i]);
        return sum;
    }
    int maxRotateFunction(vector<int>& nums) {
        n = nums.size();
        int prev = calculate(nums);
        int sum = accumulate(begin(nums), end(nums), 0);
        int result = prev;
        for (int i = 0; i < n; i++) {
            int curr = prev + sum - (n * nums[n - 1 - i]);
            result = max(result, curr);
            prev = curr;
        }
        return result;
    }
};
