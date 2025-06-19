class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int subsequence=1;
        sort(begin(nums),end(nums));
        int minnum=nums[0];
        int maxnum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            minnum=min(minnum,nums[i]);
            maxnum=max(maxnum,nums[i]);
            if(maxnum-minnum>k) 
            {
                subsequence++;
                minnum=nums[i];
                maxnum=nums[i];
            }
        }
        return subsequence;
    }
};
