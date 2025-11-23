class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> remain1;
        vector<int> remain2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (nums[i] % 3 == 1)
                remain1.emplace_back(nums[i]);
            if (nums[i] % 3 == 2)
                remain2.emplace_back(nums[i]);
        }

        if (sum % 3 == 0)
            return sum;
        sort(begin(remain1), end(remain1));
        sort(begin(remain2), end(remain2));
        int remainder = sum % 3;
        int result = 0;

        if (remainder == 1) {
            int remove1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
            int remove2 =
                remain2.size() >= 2 ? remain2[0] + remain2[1] : INT_MAX;
            result = max(result, sum - min(remove1, remove2));
        } else {
            int remove1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
            int remove2 =
                remain1.size() >= 2 ? remain1[0] + remain1[1] : INT_MAX;
            result = max(result, sum - min(remove1, remove2));
        }
        return result;
    }
};
