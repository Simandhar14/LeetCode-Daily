//cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int moves = 0;
        for (int i = 0; i < n; i++) {
            moves += abs(nums.back() - nums[i]);
        }
        return moves;
    }
};
