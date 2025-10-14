class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = i + k;
        int n = nums.size();
        while (j + k - 1 < n) {
            int start = i;
            int end = i + k - 1;
            bool notincreasing1=false,notincreasing2=false;
            while (start <= end - 1) {
                if (nums[start] >= nums[start + 1]) {
                    notincreasing1 = true;
                    break;
                }
                start++;
            }
            start = j;
            end = j + k - 1;
            while (start <= end - 1) {
                if (nums[start] >= nums[start + 1]) {
                    notincreasing2 = true;
                    break;
                }
                start++;
            }
            if (!notincreasing1 && !notincreasing2)
                return true;
            i++;
            j++;
        }
        return false;
    }
};
