class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result=0;
        int minkidx=-1;
        int maxkidx=-1;
        int overflowidx=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==minK) minkidx=i;
            if(nums[i]==maxK) maxkidx=i;
            if(nums[i]<minK || nums[i]>maxK) overflowidx=i;
            int smalleridx=min(minkidx,maxkidx);
            int subarray=smalleridx-overflowidx;
            result+= subarray<=0 ? 0 : subarray;
        }
        return result;
    }
};
