class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarray=0;
        int j=0,i=-1;
        int n=nums.size();
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=0) continue;
             i=j;
            while(i<n && nums[i]==0) {
                subarray+=i-j+1;
                i++;
            }
            j=i-1;
        }
        return subarray;
    }
};
