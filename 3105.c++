class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int count=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1]) count++;
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        ans=max(ans,count);
        count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1]) count++;
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};