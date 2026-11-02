//cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int mid=nums[n/2],moves=0;
        for(int i=0;i<n/2;i++)
        {
            moves+=abs(nums[i]-mid);
            moves+=abs(nums[n-1-i]-mid);
        }
        return moves;
    }
};
