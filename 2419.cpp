class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int result=1;
         int maxval = *max_element(begin(nums), end(nums));
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxval)
                len++;
            else {
            result=max(result,len);
            len=0;
            }
        }
        result=max(result,len);
        return result;
    }
};
