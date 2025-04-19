class Solution {
public:
int lowerbound(vector<int>&nums,int val,int left)
{
    int right=nums.size();
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]>=val)
        {
            right=mid;
        }else left=mid+1;
    }
    return left;
}
int upperbound(vector<int>&nums,int val,int left)
{
    int right=nums.size();
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]>val)
        {
            right=mid;
        }else left=mid+1;
    }
    return left;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long result=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++)
        {
            int idx1=lowerbound(nums,lower-nums[i],i+1);
            int x=idx1-i-1;
            int idx2=upperbound(nums,upper-nums[i],i+1);
            int y=idx2-i-1;
            result+=y-x;
        }
        return result;
    }
};
