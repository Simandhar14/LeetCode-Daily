//cpp
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxarr(n);
        vector<int> prefixGcd(n);
        maxarr[0] = nums[0];
        prefixGcd[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxarr[i] = max(maxarr[i - 1], nums[i]);
            prefixGcd[i] = __gcd(nums[i], maxarr[i]);
        }
        sort(begin(prefixGcd), end(prefixGcd));
        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += __gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }
        return sum;
    }
};
