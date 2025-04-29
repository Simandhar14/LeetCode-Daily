class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum=*max_element(begin(nums),end(nums));
        int count=0;
        int n=nums.size();
        long long result=0;
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==maxnum) count++;
            while(i<=j && count==k)
            {
                result+=n-j;
                if(nums[i]==maxnum) count--;
                i++;
            }
        }
        return result;
    }
};
