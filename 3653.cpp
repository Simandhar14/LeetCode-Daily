//cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& arr : queries) {
            int l = arr[0];
            int r = arr[1];
            int k = arr[2];
            int v = arr[3];
            int idx = l;
            while (idx <= r) {
                nums[idx] = (1LL*nums[idx] * v) % MOD;
                idx += k;
            }
        }
        int resultXor = 0;
        for (int& num : nums)
            resultXor ^= num;
        return resultXor;
    }
};
