class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX, count1 = 0;
        count1 = count(begin(nums), end(nums), 1);
        if (count1)
            return n - count1;
        for (int i = 0; i < n; i++) {
            int operations = 0;
            int currgcd = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (currgcd == 1) {
                    result = min(result, operations + n - 1);
                }
                int gcdval = __gcd(nums[j], currgcd);
                currgcd = gcdval;
                operations++;
            }
            if (currgcd == 1) {
                result = min(result, operations + n - 1);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
