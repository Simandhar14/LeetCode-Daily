//cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxnum = *max_element(begin(nums), end(nums));
        vector<int> freq(maxnum + 1, 0);
        for (int& num : nums) {
            freq[num]++;
        }
        if (freq[maxnum] > 1)
            return (maxnum - 1) * (maxnum - 1);
        for (int i = maxnum - 1; i >= 0; i--) {
            if (freq[i] > 0)
                return (maxnum - 1) * (i - 1);
        }
        return -1;
    }
};
