//cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int even = 0, odd = 0;
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                if (!st.count(nums[j])) {
                    if (nums[j] % 2 == 0)
                        even++;
                    else
                        odd++;
                    st.insert(nums[j]);
                }
                if (even == odd)
                    result = max(result, j - i + 1);
            }
        }
        return result;
    }
};
