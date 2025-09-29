class Solution {
public:
int bs(vector<int>& nums,int j,int val)
{
    int l=j;
    int r=nums.size()-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(val<=nums[mid])
        {
            r=mid-1;
        }else {
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int triangles=0;
        for (int i = 0; i <=n-3; i++) {
            for(int j=i+1;j<=n-2;j++)
            {
                int val=bs(nums,j+1,nums[i]+nums[j]);
                if(val!=-1)
                {
                    triangles+=val-j;
                }
            }
        }
        return triangles;
    }
};
