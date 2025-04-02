class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        vector<pair<long long, int>> diff;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diff.push_back({nums[i] - nums[j], j});
            }
        }
        for (auto val : diff) {
            int idx = val.second;
            long long value = val.first;
            for (int k = idx + 1; k < n; k++) {
                ans = max(ans, value * nums[k]);
            }
        }
        return ans < 0 ? 0 : ans;
    }
};
