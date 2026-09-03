//cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int oddCount = 0, evenCount = 0, count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                count++;
                oddCount++;
            } else if (nums[i] % 2 == 0) {
                if (oddCount > 0)
                    count++;
                 evenCount++;
            }
        }
        if (count == n)
            return true;
        oddCount = 0, evenCount = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                count++;
                evenCount++;
            } else if (nums[i] % 2 == 1) {
                if (oddCount > 0)
                    count++;
                    oddCount++;
            }
        }
        return count == n;
    }
};
