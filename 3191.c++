class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
                if(i+2>=n) return -1;
                else{
                    for(int j=i;j<=i+2;j++)
                    {
                        nums[j]=1-nums[j];
                    }
                }
            }
        }
        return count;
    }
};
