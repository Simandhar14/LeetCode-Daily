class Solution {
public:
int M=1e9+7;
long long calculatepower(int a,int b)
{
    if(b==0) return 1;
    long long result=1;
    long long half=calculatepower(a,b/2);
     result= (half*half)%M;
    if(b%2==1)
    {
        result=(result*a) % M;
    }
    return result % M;
}
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<=j)
        {
            if(nums[i]+nums[j]<=target)
            {
                int window=j-i;
                long long combinations = calculatepower(2,window);
                ans=(ans + combinations) % M;
               i++;
            }else j--;
        }
        return ans % M;
    }
};
