//cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxel = *max_element(begin(nums), end(nums));
        int moves = 0;
        for (int i = 0; i < n; i++) {
            moves += maxel - nums[i];
        }
        return moves;
    }
};
