class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n, false);
        string num = "";
        for (int i = 0; i < n; i++) {
            num.push_back(nums[i] + '0');
            int decimal = 0;
            for (int j = 0; j < num.size(); j++) {
                decimal = ((decimal * 2) + (num[j] - '0')) % 5;
            }
            if (decimal == 0)
                ans[i] = true;
        }
        return ans;
    }
};
