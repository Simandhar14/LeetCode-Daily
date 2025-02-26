//using kadane's algorithm

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxres=nums[0];
        int maxending=nums[0];
        for(int i=1;i<n;i++)
        {
            maxending=max(maxending+nums[i],nums[i]);
            maxres=max(maxres,maxending);
        }
        int minres=nums[0];
        int minending=nums[0];
         for(int i=1;i<n;i++)
        {
            minending=min(minending+nums[i],nums[i]);
            minres=min(minres,minending);
        }
        return max(abs(minres),abs(maxres));
    }
};

//using recursion - TLE
class Solution {
public:
int result=INT_MIN;
void solve(vector<int>&nums,int sum,int i)
{
    if(i>=nums.size()) return;
    sum+=nums[i];
    result=max(result,abs(sum));
    solve(nums,sum,i+1);
    solve(nums,0,i+1);
}
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        solve(nums,sum,0);
        return result;
    }
};