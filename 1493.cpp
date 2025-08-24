class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool zero=false;
        int sum=0;
        int i=0;
        int n=nums.size();
        int ans=INT_MIN;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==1) sum+=nums[j];
            else if(nums[j]==0 && zero==false) {
                zero=true;
            }
            else{
                while(i<n && nums[i]!=0)
                {
                    sum-=nums[i];
                    i++;
                }
                i++;
            }
            ans=max(ans,sum);
        }
        return zero==false ? ans-1 : ans;
    }
};
