class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int maxnum=*max_element(begin(nums),end(nums));
        vector<int>freq(maxnum+k+1,0);
        for(int &num:nums) freq[num]++; //store normal freq
        for(int i=1;i<=maxnum+k;i++) //convert freq to cummulative freq
        {
            freq[i]+=freq[i-1];
        }
        int ans=1;
        for(int num=0;num<=maxnum;num++)
        {
            int left=max(0,num-k);
            int right=num+k;
            int count=freq[right]-freq[left-1>=0 ? left-1 : 0];
            int countOfNum=freq[num]-freq[num-1>=0 ? num-1 : 0];
            int requiredOperations=count-countOfNum;
            int possibleOperations=countOfNum+min(requiredOperations,numOperations);
            ans=max(ans,possibleOperations);
        }
        return ans;
    }
};
