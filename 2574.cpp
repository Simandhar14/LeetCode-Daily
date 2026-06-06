//cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(begin(nums),end(nums),0);
        vector<int>result(n);
        int leftSum=0;
        for(int i=0;i<n;i++)
        {
            result[i]=abs(leftSum-(totalSum-nums[i]));
            leftSum+=nums[i];
            totalSum-=nums[i];
        }
        return result;
    }
};
