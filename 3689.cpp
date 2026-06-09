//cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxval = *max_element(begin(nums), end(nums));
        long long minval = *min_element(begin(nums), end(nums));
        return 1LL*(maxval - minval) * k;
    }
};
