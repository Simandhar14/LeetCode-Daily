class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask=0;
        int maxlen=1;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(j<i && (mask & nums[i])!=0)
            {
                mask^=nums[j];
                j++;
            }
            mask=mask | nums[i];
            maxlen=max(maxlen,i-j+1);
        }
        return maxlen;
    }
};
