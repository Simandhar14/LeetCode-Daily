//cpp
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> freq(201, false);
        for (int& num : nums) {
            if (num % k == 0)
                freq[num] = true;
        }
        for (int i = 1; i <= n + 1; i++) {
            if (freq[i * k] == false)
                return i * k;
        }
        return -1;
    }
};
