class Solution {
public:
    bool solve(vector<int>& nums, int i, bool left, int remaining) {
        int n = nums.size();
        if (i < 0 || i >= n)
            return remaining == 0;

        if (nums[i] == 0) {
            int direction = left ? -1 : 1;
            return solve(nums, i + direction, left, remaining);
        } 
        if (nums[i] > 0) {
            nums[i]--;
            int direction = left ? 1 : -1;
            return solve(nums, i + direction, !left, remaining - 1);
        }
        return false;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (bool left : {true, false}) {
                    vector<int> temp = nums;
                    if (solve(temp, i, left, total))
                        count++;
                }
            }
        }
        return count;
    }
};
